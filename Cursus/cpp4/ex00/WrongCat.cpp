#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!\n";
}