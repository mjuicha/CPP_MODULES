#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie( std::string str );
        ~Zombie();
        void    set_name(std::string str);
};

Zombie* zombieHorde( int N, std::string name );

#endif