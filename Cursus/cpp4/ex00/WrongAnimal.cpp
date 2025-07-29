#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Generic wrong animal sound\n";
}