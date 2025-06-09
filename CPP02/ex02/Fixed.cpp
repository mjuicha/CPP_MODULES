#include "Fixed.hpp"

/************************ Orthodox Canonical Form **************************/

Fixed::Fixed()
{
    number = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    *this = fix;
}

Fixed &Fixed::operator=(const Fixed& fix)
{
    if (this != &fix)
        this->number = fix.number;
    return *this;
}

Fixed::~Fixed()
{}

/******************** Constructors for int and float **************/

Fixed::Fixed(const int nbr)
{
    number = nbr << bits;
}

Fixed::Fixed(const float flt)
{
    number = roundf(flt * 256);
}

/************************* Comparison Operators **************************/ 

bool Fixed::operator>(const Fixed& fix) const
{
    return (this->number > fix.number);
}
bool Fixed::operator<(const Fixed& fix) const
{
    return (this->number < fix.number);
}
bool Fixed::operator>=(const Fixed& fix) const
{
    return (this->number >= fix.number);
}
bool Fixed::operator<=(const Fixed& fix) const
{
    return (this->number <= fix.number);
}
bool Fixed::operator==(const Fixed& fix) const
{
    return (this->number == fix.number);
}
bool Fixed::operator!=(const Fixed& fix) const
{
    return (this->number != fix.number);
}

/************************* Arithmetic Operators **************************/

Fixed Fixed::operator+(const Fixed& fix)
{
    Fixed result;
    result.number = this->number + fix.number;
    return result;
}
Fixed Fixed::operator-(const Fixed& fix)
{
    Fixed result;
    result.number = this->number - fix.number;
    return result;
}
Fixed Fixed::operator*(const Fixed& fix)
{
    Fixed result;
    result.number = (this->number * fix.number) >> bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& fix)
{
    Fixed result;
    result.number = (this->number << bits) / fix.number;
    return result;
}

/************************* Increment and Decrement Operators ****************/

Fixed& Fixed::operator++()
{
    ++this->number;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->number++;
    return old;
}

Fixed& Fixed::operator--()
{
    --this->number;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->number++;
    return old;
}

/************************* Min and Max Functions **************************/

Fixed& Fixed::min(Fixed& fix1, Fixed& fix2)
{
    return fix1.number < fix2.number ? fix1 : fix2;
}

Fixed& Fixed::max(Fixed& fix1, Fixed& fix2)
{
    return fix1.number > fix2.number ? fix1 : fix2;
}

const Fixed& Fixed::min(const Fixed& fix1, const Fixed& fix2)
{
    return fix1.number < fix2.number ? fix1 : fix2;
}

const Fixed& Fixed::max(const Fixed& fix1, const Fixed& fix2)
{
    return fix1.number > fix2.number ? fix1 : fix2;
}

/************************* Output Operator **************************/

std::ostream& operator<<(std::ostream& out, const Fixed& fix)
{
    out << fix.toFloat();
    return out;
}

/************************* Conversion Functions **************************/

float   Fixed::toFloat( void ) const
{
    return (float)number / 256;
}

int     Fixed::toInt( void ) const
{
    return number >> bits;
}
