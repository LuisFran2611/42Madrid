#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("DiamondBoy");

    d.attack("a robot");
    d.takeDamage(40);
    d.beRepaired(30);
    d.whoAmI();

    return 0;
}