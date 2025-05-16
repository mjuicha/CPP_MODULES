#include "Fixed.hpp"

Fixed::Fixed()
{
    number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fix;
}

Fixed &Fixed::operator=(const Fixed& fix)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fix)
        this->number = fix.number;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    number = nbr << bits;
}

Fixed::Fixed(const float flt)
{
    std::cout << "Float constructor called" << std::endl;
    number = roundf(flt * (1 << bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fix)
{
    out << fix.toFloat();
    return out;
}

float   Fixed::toFloat( void ) const
{
    return (float)number / 256;
}

int     Fixed::toInt( void ) const
{
    return number >> bits;
}
