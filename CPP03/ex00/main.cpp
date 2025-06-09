#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("Fighter");

    clap.attack("EnemyA");
    clap.takeDamage(4);
    clap.beRepaired(3);
    clap.beRepaired(5);
    clap.attack("EnemyB");
    clap.takeDamage(14);
    clap.beRepaired(3);
    return 0;
}
