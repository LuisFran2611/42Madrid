#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Robot1");
    a.attack("Enemy");
    a.takeDamage(4);
    a.beRepaired(3);
    a.attack("Enemy2");
    a.takeDamage(10);
    a.beRepaired(5);
    return 0;
}