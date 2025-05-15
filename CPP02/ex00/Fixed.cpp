#include "Fixed.hpp"

Fixed::Fixed()
{
    number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nbr)
{
    number = nbr;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed& fix)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return fix;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return number;
}

void    Fixed::setRawBits( int const raw )
{
    number = raw;
}