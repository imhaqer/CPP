/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:52:16 by hahamdan          #+#    #+#             */
/*   Updated: 2025/07/15 12:48:21 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

void PhoneBook::addContact() {

    std::string first, last, nick, phone, secret;

    std::cout << "\033[1mEnter contact details:\033[0m\n\n";
    std::cout << "\033[1mFirst Name: \033[0m";

    std::getline(std::cin, first);
    if (first.empty())
    {
    	std::cout << "\033[1;33mRequired field cannot be emtpy.\033[0m\n";
    	return;
    }
    std::cout << "\033[1mLast Name: \033[0m";
    std::getline(std::cin, last);
    if (last.empty())
    {
    	std::cout << "\033[1;33mRequired field cannot be emtpy.\033[0m\n";
    	return;
    }
    std::cout << "\033[1mNickname: \033[0m";
    std::getline(std::cin, nick);
    if (nick.empty())
    {
    	std::cout << "\033[1;33mRequired field cannot be emtpy.\033[0m\n";
    	return;
    }
    std::cout << "\033[1mPhone Number: \033[0m";
    std::getline(std::cin, phone);
    if (phone.empty())
    {
    	std::cout << "\033[1;33mRequired field cannot be emtpy.\033[0m\n";
    	return;
    }
    std::cout << "\033[1mDarkest Secret: \033[0m";
    std::getline(std::cin, secret);
    if (secret.empty())
    {
    	std::cout << "\033[1;33mRequired field cannot be emtpy.\033[0m\n";
    	return;
    }

    contact[currentIndex].setDetails(first, last, nick, phone, secret);

    currentIndex = (currentIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::searchContact() const{

    std::string index;

    if (contactCount == 0)
    {
        std::cout << "\033[1;33mPhonebook is empty!\033[0m\n";
        return ;
    }
    std::cout << "\n|  index   |First Name|Last Name | Nickname |\n";
    std::cout << "|----------|----------|----------|----------|\n";


    for (int i = 0; i < contactCount; i++)
        contact[i].displaySummary(i);

    std::cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";

   
   
    std::cout << "\n\033[1mEnter index to display: \033[0m";


    if (!std::getline(std::cin, index)) {
        if (std::cin.eof()) {
            std::cout << "\n(EOF detected - exiting search)\n";
        }
        else {
            std::cout << "\n(Input error - exiting search)\n";
        }
        return;
    }
    if (index.empty()) {
        std::cout << "\033[1;31mEmpty input! Please enter an index.\033[0m\n";
        return;
    }
    if  (index.length() != 1) {
            std::cout  << "\033[1;31mPlease enter a valid number!\033[0m\n";
            return ; }
        

    try {
    int nbr = std::stoi(index);
    std::cout << nbr << std::endl;
    if (nbr >= 0 && nbr < contactCount)
        contact[nbr].displayFull();
    else 
        std::cout << "\033[1;31mInvalid range!\033[0m\n";
    }
    catch (...) {
        std::cout << "\033[1;31mPlease enter a valid number!\033[0m\n";
    }

}