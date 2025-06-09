#include "Zombie.hpp"

int main()
{
    Zombie* z;
    int     N = 10;
    z = zombieHorde(N, "Zombie");
    if (!z)
        return 1;
    for (int i = 0; i < N; i++)
    {
        z[i].announce();
    }
    delete [] z;
    return 0;
}
