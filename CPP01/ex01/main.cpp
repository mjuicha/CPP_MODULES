#include "Zombie.hpp"

# define N 1
int main()
{
    Zombie* z;
    z = zombieHorde(N, "simo");
    if (!z)
        return 1;
    for (int i = 0; i < N; i++)
    {
        z[i].announce();
    }
    delete [] z;
    z = NULL;
    return 0;
}