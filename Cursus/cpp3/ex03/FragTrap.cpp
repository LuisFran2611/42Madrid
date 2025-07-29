#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed.\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructed.\n";
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "FragTrap " << name << " can't attack (no HP or energy).\n";
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " launches an explosive attack on "
              << target << ", causing " << attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a positive high five! \n";
}