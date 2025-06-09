#include "HumanA.hpp"

void    HumanA::attack( void )
{
    std::cout << name << " attacks with their " << weap.getType();
    std::cout << std::endl;
}

HumanA::HumanA(std::string str, Weapon& weeeap)
    : name(str), weap(weeeap) {}