#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void PhoneBook::addContact() {
    int index = (count < 8) ? count : oldest;
    contacts[index].setInfo();
    if (contacts[index].isEmpty())
    {
        std::cout << "Contact information is incomplete. Not added." << std::endl;
        return;
    }
    if (count < 8)
        count++;
    else
        oldest = (oldest + 1) % 8;
}

extern std::string formatField(const std::string& field);

void PhoneBook::searchContacts() const {
    if (count == 0) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

    for (int i = 0; i < count; ++i) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << formatField(contacts[i].getFirstName());
        std::cout << "|" << formatField(contacts[i].getLastName());
        std::cout << "|" << formatField(contacts[i].getNickname()) << "|" << std::endl;
    }

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    
    int index = -1;
    if (input.length() == 1 && isdigit(input[0])) {
        index = input[0] - '0';
    }

    if (index < 0 || index >= count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    contacts[index].printDetails();
}