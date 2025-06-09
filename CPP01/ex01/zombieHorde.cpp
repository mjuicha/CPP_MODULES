#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string str )
{
    if (N <= 0)
    {
        std::cerr << "Error: N must be > 0" << std::endl;
        return NULL;
    }
    Zombie* z = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        z[i].set_name(str);
    }

    return z;
}
