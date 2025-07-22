#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n" << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlFunc)();
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunc funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }
}