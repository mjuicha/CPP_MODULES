#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor was created for " << name << "!!!" << std::endl;
}

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
    name = str;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor was created for " << name << "!!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "FragTrap copy constructor was created for " << copy.name << "!!!" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap assignment operator was created for " << copy.name << "!!!" << std::endl;
    if (this != &copy)
    {
        name = copy.name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor was called for " << name << "!!!" << std::endl;
}

/**************** Member Functions ****************/

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " is asking for a high five!" << std::endl;
}
