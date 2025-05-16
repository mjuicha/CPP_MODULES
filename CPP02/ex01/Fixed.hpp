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

        Fixed(const int nbr);
        Fixed(const float flt);

        float   toFloat( void ) const;
        int     toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& fix);

#endif