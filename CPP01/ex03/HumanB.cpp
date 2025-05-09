#include "HumanB.hpp"

void    HumanB::attack( void )
{
    std::cout << name << " attacks with their " << (*weap).getType()
    << std::endl;
}

HumanB::HumanB(std::string str)
: name(str), weap(NULL) {}

HumanB::HumanB(std::string str, Weapon &club)
     : name(str), weap(&club) {}


void    HumanB::setWeapon(Weapon &weeep)
{
    weap = &weeep;
}