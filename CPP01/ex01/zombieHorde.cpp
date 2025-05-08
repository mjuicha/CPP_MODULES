#include "Zombie.hpp"

void    Zombie::set_name(std::string str)
{
    name = str;
    std::cout << name <<" is setted\n";
}

Zombie* zombieHorde( int N, std::string str )
{
    Zombie* z = new Zombie[N];
    for (int i = 0; i < N; i++)
        z[N].set_name(str);
    return z;
}
