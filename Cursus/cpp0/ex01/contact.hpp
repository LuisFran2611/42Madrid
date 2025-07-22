#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setInfo();
    void printSummary(int index) const;
    void printDetails() const;
    bool isEmpty() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
};

#endif