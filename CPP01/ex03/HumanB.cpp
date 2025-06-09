#include "HumanB.hpp"

void    HumanB::attack( void )
{
    if (weap == NULL)
    {
        std::cout << name << " has no weapon to attack with." << std::endl;
        return ;
    }
    std::cout << name << " attacks with their " << (*weap).getType();
    std::cout << std::endl;
}

HumanB::HumanB(std::string str)
: name(str), weap(NULL) {}

void    HumanB::setWeapon(Weapon &weeeap)
{
    weap = &weeeap;
}