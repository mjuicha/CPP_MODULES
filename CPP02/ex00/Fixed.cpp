#include "Fixed.hpp"

Fixed::Fixed()
{
    number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy constructor called" << std::endl;
    number = fix.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& fix)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fix)
        this->number = fix.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void    Fixed::setRawBits( int const raw )
{
    number = raw;
}
 