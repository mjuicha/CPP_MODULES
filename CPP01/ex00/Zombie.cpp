#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string str )
{
    name = str;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie: "<< name << " has been destroyed" << std::endl;
}
