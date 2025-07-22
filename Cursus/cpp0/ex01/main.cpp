#include "phonebook.hpp"
#include <iostream>
#include <string>

std::string formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return std::string(10 - field.length(), ' ') + field;
}

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}