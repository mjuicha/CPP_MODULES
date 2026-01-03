#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        data = other.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

bool isValueValid(float value)
{
    return value >= 0 && value <= 1000;
}

bool isDateValid(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    year = std::stoi(date.substr(0, 4));
    month = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = {0, 31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28,
                         31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month])
        return false;
    return true;
}


float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = data.upper_bound(date);
    if (it == data.begin())
        throw std::runtime_error("Error: no exchange rate available for this date");
    --it;
    return it->second;
}

void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    int linecount = 1;

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file");

    std::string line;

    while (line.empty())
    {
        if (!std::getline(file, line))
            throw std::runtime_error("Error: empty database file");
    }

    std::stringstream ss(line);
    std::string date_col, value_col;

    if (!std::getline(ss, date_col, ',') || !std::getline(ss, value_col, ','))
        throw std::runtime_error("Error at line " + std::to_string(linecount) + ": invalid CSV header");
    if (std::getline(ss, line))
        throw std::runtime_error("Error at line " + std::to_string(linecount) + ": More than 2 fields");
    
    date_col = trim(date_col);
    value_col = trim(value_col);

    if (date_col != "date" || value_col != "value")
        throw std::runtime_error("Error at line " + std::to_string(linecount) + ": invalid CSV header");

    while (std::getline(file, line))
    {
        linecount++;
        
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date_str, value_str;

        if (!std::getline(ss, date_str, ',') || !std::getline(ss, value_str, ','))
            throw std::runtime_error("Error at line " + std::to_string(linecount) + ": invalid CSV format");
        if (std::getline(ss, line))
            throw std::runtime_error("Error at line " + std::to_string(linecount) + ": More than 2 fields");

        date_str = trim(date_str);
        value_str = trim(value_str);

        if (date_str.empty() || value_str.empty())
        {
            std::cerr << "Error at line " << linecount << ": empty date or value field" << std::endl;
            continue;
        }

        if (!isDateValid(date_str))
            throw std::runtime_error("Error at line " + std::to_string(linecount) + ": invalid date => " + date_str);
        std::stringstream value_ss(value_str);
        float value;
        value_ss >> value;
        if (!value_ss.eof())
            throw std::runtime_error("Error at line " + std::to_string(linecount) + ": invalid value => " + value_str);
        if (value < 0)
            throw std::runtime_error("Error at line " + std::to_string(linecount) + ": negative value => " + value_str);
        data[date_str] = value;
    }
    if (data.empty())
        throw std::runtime_error("Error: empty database file");
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file");
    
    std::string line;
    
    if (!std::getline(file, line))
    {
        file.close();
        throw std::runtime_error("Error: empty input file");
    }
    if (trim(line) != "date | value")
    {
        file.close();
        throw std::runtime_error("Error: invalid input file header");
    }
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t PipePos = line.find('|');
        if (PipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date_str = trim(line.substr(0, PipePos));
        std::string value_str = trim(line.substr(PipePos + 1));

        if (date_str.empty() || value_str.empty())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isDateValid(date_str))
        {
            std::cerr << "Error: bad input => " << date_str << std::endl;
            continue;
        }

        std::stringstream value_ss(value_str);
        float value;
        value_ss >> value;

        if (!value_ss.eof())
        {
            std::cerr << "Error: bad input => " << value_str << std::endl;
            continue;
        }
        if (!isValueValid(value))
        {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large number." << std::endl;
            continue;
        }
        try 
        {
            float ExchangeRate = getExchangeRate(date_str);
            std::cout << date << " => " << value << " = " << (value * ExchangeRate) << std::endl;

        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: bad value => " << value_str << std::endl;
        }

}