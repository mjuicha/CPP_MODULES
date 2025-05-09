#include "Weapon.hpp"

Weapon::Weapon( std::string str )
{
    type = str;
}

Weapon::Weapon()
{

}
std::string Weapon::getType( void ) const
{
    return type;
}

void    Weapon::setType( std::string value )
{
    type = value;
}


//done