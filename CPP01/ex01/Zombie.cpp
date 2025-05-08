#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "test\n";
}

Zombie::Zombie( std::string str )
{
    name = str;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie: "<< name << " has been destroyed" << std::endl;
}

//done