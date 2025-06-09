#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Fighter");

    clap.attack("EnemyA");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.attack("EnemyB");
    clap.takeDamage(12);
    clap.attack("EnemyC");

    std::cout << std::endl;

    ScavTrap scav("Guardian");

    scav.attack("EnemyA");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.attack("EnemyA");
    scav.takeDamage(50);
    scav.attack("EnemyC");
    scav.guardGate();

    std::cout << std::endl;

    FragTrap frag("Blaster");

    frag.attack("EnemyA");
    frag.takeDamage(20);
    frag.beRepaired(15);
    frag.attack("EnemyB");
    frag.takeDamage(40);
    frag.attack("EnemyC");
    frag.highFivesGuys();

    return 0;
}
