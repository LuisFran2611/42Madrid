#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}