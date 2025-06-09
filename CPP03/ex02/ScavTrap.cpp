#include "ScavTrap.hpp"

/********************** Orthodox Canonical Form **********************/

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "default";
    hitPoints = 100;
    attackDamage = 20;
    energyPoints = 50;
    std::cout << "ScavTrap constructing default was called!!" << std::endl;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    name = str;
    hitPoints = 100;
    attackDamage = 20;
    energyPoints = 50;
    std::cout << "ScavTrap constructing with name was called for " << name << "!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ct) : ClapTrap(ct)
{
    std::cout << "ScavTrap copy constructor was called for " << ct.name << "!!" << std::endl;
    *this = ct;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ct)
{
    std::cout << "ScavTrap assignment operator was called for " << ct.name << "!!" << std::endl;
    if (this != &ct)
    {
        name = ct.name;
        hitPoints = ct.hitPoints;
        attackDamage = ct.attackDamage;
        energyPoints = ct.energyPoints;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor was called for " << name << "!!" << std::endl;
}

/********************** Member Functions **********************/

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ScavTrap " << name << " fires at " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " is out of energy and cannot attack." << std::endl;
    }
    else if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " is out of hit points and cannot attack." << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
