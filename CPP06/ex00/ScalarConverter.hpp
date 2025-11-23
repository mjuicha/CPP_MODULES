#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat>   

enum type
{
    CHAR,
    DOUBLE,
    STRING,
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        ~ScalarConverter();

        static void convert(const std::string &input);
};



#endif


// detect type 

// string > ORtype > 3types > display


// SPECIAL CASES
//{
    // ** no senses **
    // ** overflow **
    // 

//}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


// handle CHAR
// {
//      * non displayable => informative msg xxxxx ==> Non displayable
// }
// handle INT
// {
//      * easy
// }
// handle FLOAT
// {
//      * in last char is f
//      * handle pseudo-literals : -inff, +inff, nanf
// }
// handle DOUBLE
// {
//      * also handle pseudo-literals : -inf, +inf, nan
//      * no f at the end
// }
//
// ** IMPOSSIBLE **

// !overflow



// check sign 
// check ints : err
// * pass ints 
// end | . | f | *
// end is end
// ** . > f | ints | end | *
// 
// 




// "c" be 'c'
// "10" be 10
// "10.0f" be 10.0f
// "10.0" be 10.0