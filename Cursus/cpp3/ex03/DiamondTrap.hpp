#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();

    void attack(const std::string& target); // usa ScavTrap::attack
    void whoAmI();
};

#endif