#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    // Llenar array
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Probar ideas
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "I want a bone.");
    Dog* dog2 = new Dog(*dog1);

    std::cout << dog2->getIdea(0) << std::endl;
    dog1->setIdea(0, "Changed idea.");
    std::cout << dog2->getIdea(0) << std::endl;

    delete dog1;
    delete dog2;

    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}