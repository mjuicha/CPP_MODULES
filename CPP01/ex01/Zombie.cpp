#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string str)
{
    name = str;
}

Zombie::Zombie()
{}

Zombie::~Zombie( void )
{
    std::cout << "Zombie: "<< name << " has been destroyed" << std::endl;
}
