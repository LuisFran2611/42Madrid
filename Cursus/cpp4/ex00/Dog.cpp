#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}