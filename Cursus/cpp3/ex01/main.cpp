#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap c("Basic");
    c.attack("a target");
    c.takeDamage(5);
    c.beRepaired(2);

    std::cout << "--------------------\n";

    ScavTrap s("Guardian");
    s.attack("an intruder");
    s.takeDamage(30);
    s.beRepaired(20);
    s.guardGate();

    return 0;
}