#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this; // handle self-assignment
    return *this;
}

ScalarConverter::~ScalarConverter()
{}



void    trim_string(std::string &p_string)
{
    size_t start = p_string.find_first_not_of(" \t\n\v\f\r");
    size_t end = p_string.find_last_not_of(" \t\n\v\f\r");

    if (start == std::string::npos)
        p_string = "";
    else
        p_string = p_string.substr(start, end - start + 1);
}

bool isNumeric(std::string &p_string)
{
    if (p_string.length() == 0)
        return false;
    int end = p_string.length() - 1;
    if (p_string[end] == 'f')
        p_string = p_string.substr(0, end);
    for (size_t i = 0; i < p_string.length(); i++)
    {
        if (i == 0 && (p_string[i] == '+' || p_string[i] == '-'))
            continue;
        if (p_string[i] == '.')
        {
            if (p_string[i + 1] == '\0')
                return false;
            continue;
        }
        if (!isdigit(p_string[i]))
            return false;
    }
    return true;
}

int     detect_type(std::string &p_string)
{
    trim_string(p_string);
    if (p_string.length() == 1 && !isdigit(p_string[0]))
    {
        return CHAR;
    }
    else if (isNumeric(p_string))
    {
        return DOUBLE;
    }
    return STRING;
}

///////////////////////////////////////
///////////////////////////////////////

std::string toChar(std::string &p_string, int type)
{
    double value = std::strtod(p_string.c_str(), NULL);
     if (type == CHAR)
        return p_string;
    else if (type == STRING || value <= 0 || value > 127)
        return "impossible";
    else if (value < 32 || value == 127)
        return "Non displayable";
    else
        return "'" + std::string(1, static_cast<char>(value)) + "'";
}

std::string toInt(std::string &p_string, int type)
{
    double value = std::strtod(p_string.c_str(), NULL);
    std::string result;
    if (type == CHAR)
        result = std::to_string(static_cast<int>(p_string[0]));
    else if (type == STRING || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        result = "impossible";
    else
        result = std::to_string(static_cast<int>(value));
    return result;
}

std::string toFloat(std::string &p_string, int type)
{
    double value = std::strtod(p_string.c_str(), NULL);
    std::string result;
    float Float;

    if (type == CHAR)
        Float = static_cast<float>(p_string[0]);
    else if (type == STRING)
    {
        if (p_string == "+inf" || p_string == "+inff")
            return "+inff";
        else if (p_string == "-inf" || p_string == "-inff")
            return "-inff";
        else 
            return "nanf";
    }
    else
        Float = static_cast<float>(value);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << Float << "f";
    result = oss.str();
    return result;
}

std::string toDouble(std::string &p_string, int type)
{
    double value = std::strtod(p_string.c_str(), NULL);
    std::string result;

    if (type == CHAR)
        value = static_cast<double>(p_string[0]);
    if (type == STRING)
    {
        if (p_string == "+inf" || p_string == "+inff")
            return "+inf";
        else if (p_string == "-inf" || p_string == "-inff")
            return "-inf";
        else 
            return "nan";
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    result = oss.str();
    return result;
}


void ScalarConverter::convert(const std::string &input)
{
    std::string p_string = input;
    int type = detect_type(p_string);
    std::cout << "char: " << toChar(p_string, type) << std::endl;
    std::cout << "int: " << toInt(p_string, type) << std::endl;
    std::cout << "float: " << toFloat(p_string, type) << std::endl;
    std::cout << "double: " << toDouble(p_string, type) << std::endl;
}

// crazy tests