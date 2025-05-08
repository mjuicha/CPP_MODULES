#include "Zombie.hpp"

int main()
{
    Zombie* z;
    z = newZombie("hassan");
    z->announce();
    randomChump("la");

    delete z;
   return (0);
}

//set name