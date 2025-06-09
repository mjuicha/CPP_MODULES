#include "ClapTrap.hpp"

/********************** Orthodox Canonical Form **********************/

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string str ) : name(str), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Constructor called for " << name << "!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
    std::cout << "ClapTrap Copy constructor called for " << ct.name << "!" << std::endl;
    *this = ct;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct)
{
    std::cout << "ClapTrap Assignment operator called for " << ct.name << "!" << std::endl;
    if (this != &ct)
    {
        name = ct.name;
        hitPoints = ct.hitPoints;
        attackDamage = ct.attackDamage;
        energyPoints = ct.energyPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called for " << name << "!" << std::endl;
}

/********************** Member Functions **********************/

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
    }
    else if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points and cannot attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return;
		}
        hitPoints -= amount;
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        if (hitPoints == 0)
            std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return;
		}
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself and gains " << amount << " hitPoints!" << std::endl;
    }
    else if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy left to repair!" << std::endl;
    }
    else if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points and cannot be repaired!" << std::endl;
    }
}
