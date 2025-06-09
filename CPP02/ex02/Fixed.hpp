#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &fix);
        Fixed& operator=(const Fixed& fix);
        ~Fixed();

        // Constructors
        Fixed(const int nbr);
        Fixed(const float flt);

        // Comparison operators
        bool operator>(const Fixed& fix) const;
        bool operator<(const Fixed& fix) const;
        bool operator>=(const Fixed& fix) const;
        bool operator<=(const Fixed& fix) const;
        bool operator==(const Fixed& fix) const;
        bool operator!=(const Fixed& fix) const;

        // Arithmetic operators
        Fixed operator+(const Fixed& fix);
        Fixed operator-(const Fixed& fix);
        Fixed operator*(const Fixed& fix);
        Fixed operator/(const Fixed& fix);
    
        // Increment and Decrement operators
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        static Fixed& min(Fixed& fix1, Fixed& fix2);
        static const Fixed& min(const Fixed& fix1, const Fixed& fix2);

        static Fixed& max(Fixed& fix1, Fixed& fix2);
        static const Fixed& max(const Fixed& fix1, const Fixed& fix2);

        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fix);

#endif
