#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called\n";
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}