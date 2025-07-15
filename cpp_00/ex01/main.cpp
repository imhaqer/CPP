/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:52:12 by hahamdan          #+#    #+#             */
/*   Updated: 2025/07/15 12:57:04 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "\033[1;32mWelcom to 80s PhoneBook!\033[0m\n";
    std::cout << "\033[1mCommands: ADD, SEARCH, EXIT.\033[0m\n";

    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, command)) {
            if (std::cin.eof()) {
                std::cout << "\n(EOF detected - exiting phonebook)\n";
                break;
            }
            else
                std::cout << "\033[1;31getline error!\033[0m]\n";
            }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
           phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else if (command.empty())
            continue;
        else
            std::cout << "\033[1;33mInvalid command! Try ADD, SEARCH or EXIT.\033[0m\n";
    }
    std::cout << "\033[1;31mBye, your contacts are lost forever!\033[0m\n";
    return (0);
}

