#include "ScavTrap.hpp"

int main() 
{
	ClapTrap claptrap("Fighter");
    claptrap.attack("EnemyA");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("EnemyB");
    claptrap.takeDamage(12);
    claptrap.attack("EnemyC");
    std::cout << std::endl;
    ScavTrap scavtrap("Scavenger");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(10);
    scavtrap.attack("EnemyA");
    scavtrap.takeDamage(50);
    scavtrap.attack("EnemyB");
    scavtrap.guardGate();
	std::cout << std::endl;
	return 0;
}
