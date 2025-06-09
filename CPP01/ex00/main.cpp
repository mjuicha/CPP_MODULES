#include "Zombie.hpp"

int main()
{
    Zombie* z;
    z = newZombie("HeapZombie");
    z->announce();
    randomChump("StackZombie");
    delete z;
   return (0);
}
