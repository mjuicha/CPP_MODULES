#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;
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

bool isNumeric(std::string &p_string, int *isDot)
{
    if (p_string.length() == 0)
        return false;
    int end = p_string.length() - 1;
    if (p_string[end] == 'f' && isdigit(p_string[end - 1]))
        p_string = p_string.substr(0, end);
    for (size_t i = 0; i < p_string.length(); i++)
    {
        if (i == 0 && (p_string[i] == '+' || p_string[i] == '-'))
            continue;
        if (p_string[i] == '.')
        {
            if (p_string[i + 1] == '\0')
                return false;
            *isDot += 1;
            continue;
        }
        if (!isdigit(p_string[i]))
            return false;
    }
    return true;
}

int     detect_type(std::string &p_string)
{
    int isDot = 0;
    trim_string(p_string);
    if (p_string.length() == 1 && !isdigit(p_string[0]))
        return CHAR;
    else if (isNumeric(p_string, &isDot))
    {
        if (isDot == 0)
            return INT;
        else if (isDot == 1)
            return DOUBLE;
    }
    return STRING;
}


std::string toChar(std::string &p_string, int type)
{
    double value = std::strtod(p_string.c_str(), NULL);
     if (type == CHAR)
        return "'" + std::string(1, p_string[0]) + "'";
    else if (type == STRING || value < 0 || value > 127)
        return "impossible";
    else if (((value >= 0) && (value < 32)) || value == 127)
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
        else if (p_string == "nan" || p_string == "nanf")
            return "nanf";
        else
            return "impossible";
    }
    else if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
        return "impossible";
    else
        Float = static_cast<float>(value);
    std::ostringstream oss;
    if (std::isnan(value))
        oss << "nan";
    else if (std::isinf(value))
    {
        if (value > 0)
            oss << "+inff";
        else
            oss << "-inff";
    }
    else
    {
        if (type == CHAR)
            oss << Float << ".0f";
        else if (type == INT || value == static_cast<int>(Float))
            oss << value << ".0f";
        else 
            oss << value << "f";
    }
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
        else if (p_string == "nan" || p_string == "nanf")
            return "nan";
        else
            return "impossible";
    }
    std::ostringstream oss;
    if (std::isnan(value))
        oss << "nan";
    else if (std::isinf(value))
    {
        if (value > 0)
            oss << "+inf";
        else
            oss << "-inf";
    }
    else
    {
        if (type == INT || type == CHAR || value == static_cast<int>(value))
            oss << value << ".0";
        else 
            oss << value;
    }
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
