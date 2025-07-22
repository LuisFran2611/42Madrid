#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;    // puntero a brain
    std::string& stringREF = brain;     // referencia a brain

    // Direcciones de memoria
    std::cout << "Memory address of brain:    " << &brain << std::endl;
    std::cout << "Memory address held by PTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by REF: " << &stringREF << std::endl;

    // Valores
    std::cout << "Value of brain:             " << brain << std::endl;
    std::cout << "Value pointed by PTR:       " << *stringPTR << std::endl;
    std::cout << "Value pointed by REF:       " << stringREF << std::endl;

    return 0;
}