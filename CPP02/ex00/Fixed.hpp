#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int number;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(int nbr);
        Fixed& operator=(Fixed& fix);
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif