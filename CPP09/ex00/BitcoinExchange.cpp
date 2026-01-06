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

std::string Int2String(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

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

    if (!std::isdigit(date[0]) || !std::isdigit(date[1]) || !std::isdigit(date[2]) || !std::isdigit(date[3]) ||
        !std::isdigit(date[5]) || !std::isdigit(date[6]) ||
        !std::isdigit(date[8]) || !std::isdigit(date[9]))
        return false;
        
    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
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
        {
            file.close();
            throw std::runtime_error("Error: empty database file");
        }
    }

    if (trim(line) != "date,exchange_rate")
    {
        file.close();
        throw std::runtime_error("Error at line " + Int2String(linecount) + ": invalid CSV header");
    }

    while (std::getline(file, line))
    {
        linecount++;
        
        if (line.empty())
            continue;

        std::string date_str, value_str;

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            file.close();
            throw std::runtime_error("Error at line " + Int2String(linecount) + ": invalid CSV format");
        }

        date_str = trim(line.substr(0, commaPos));
        value_str = trim(line.substr(commaPos + 1));
        if (date_str.empty() || value_str.empty())
        {
            file.close();
            throw std::runtime_error("Error at line " + Int2String(linecount) + ": empty date or value field");
        }
        if (!isDateValid(date_str))
        {
            file.close();
            throw std::runtime_error("Error at line " + Int2String(linecount) + ": invalid date => " + date_str);
        }
        std::stringstream value_ss(value_str);
        float value;
        value_ss >> value;
        if (!value_ss.eof())
        {
            file.close();
            throw std::runtime_error("Error at line " + Int2String(linecount) + ": invalid value => " + value_str);
        }
        if (value < 0)
        {
            file.close();
            throw std::runtime_error("Error at line " + Int2String(linecount) + ": negative value => " + value_str);
        }
        data[date_str] = value;
    }
    file.close();
    if (data.empty())
        throw std::runtime_error("Error: empty database file");
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file");
    
    std::string line;
    
    while (line.empty())
    {
        if (!std::getline(file, line))
        {
            file.close();
            throw std::runtime_error("Error: empty input file");
        }
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

        size_t pos;
        float value;
        try
        {
            value = std::stof(value_str, &pos);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: bad input => " << value_str << std::endl;
            continue;
        }
        
        if (pos != value_str.length())
        {
            std::cerr << "Error: bad input => " << value_str << std::endl;
            continue;
        }
        if (!isValueValid(value))
        {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        try 
        {
            float ExchangeRate = getExchangeRate(date_str);
            std::cout << date_str << " => " << value << " = " << (value * ExchangeRate) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}
