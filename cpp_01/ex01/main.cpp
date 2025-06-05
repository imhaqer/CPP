#include <iostream>
#include <string>
#include "PhoneBook.hpp"


int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcom to 80s PhoneBook!\n";
    std::cout << "Commands: ADD, SEARCH, EXIT\n";

    while (true)
    {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
           phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command! Try ADD, SEARCH or EXIT\n";
    }
    std::cout << "Goodbye!";
    return (0);
}

