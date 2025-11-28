#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat>   
#include <limits>
#include <cmath>

enum type
{
    CHAR,
    INT,
    DOUBLE,
    STRING,
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);
};

#endif
