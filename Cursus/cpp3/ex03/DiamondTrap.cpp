#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ScavTrap(name), FragTrap(name), name(name)
{
    ScavTrap::name = name + "_clap_name";
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " constructed.\n";
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destructed.\n";
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); // usar ataque de ScavTrap
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name
              << ", ClapTrap name: " << ScavTrap::name << std::endl;
}