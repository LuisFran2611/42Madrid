#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed.\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructed.\n";
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack (no HP or energy).\n";
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}