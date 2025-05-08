#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        ~Zombie();
        void    set_name(std::string str);
        void    announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif