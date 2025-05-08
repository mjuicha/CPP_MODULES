#include "Zombie.hpp"

int main()
{
    Zombie* z;
    z = zombieHorde(2, "simo");
    // delete z;
    z = NULL;
    system("leaks Brainz");
    return 0;
}