#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "--------------------\n";

    FragTrap f("Bomber");
    f.attack("an enemy");
    f.takeDamage(50);
    f.beRepaired(40);
    f.highFivesGuys();

    return 0;
}