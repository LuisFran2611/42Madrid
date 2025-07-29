#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}