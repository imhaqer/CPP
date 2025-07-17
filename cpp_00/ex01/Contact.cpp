/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:52:07 by hahamdan          #+#    #+#             */
/*   Updated: 2025/07/15 12:48:04 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setDetails(const std::string &first, const std::string &last,
		const std::string &nick, const std::string &phone,
		const std::string &secret) {
	
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone; 
	darkestSecret = secret;
}

void Contact::displayFull() const {

	std::cout << std::endl;
	std::cout << "\033[1mFirst Name: \033[0m" << firstName << std::endl;
	std::cout << "\033[1mLast Name: \033[0m" << lastName << std::endl;
	std::cout << "\033[1mNickname: \033[0m" << nickName<< std::endl;
	std::cout << "\033[1mPhone Number: \033[0m" << phoneNumber << std::endl;
	std::cout << "\033[1mDarkest Secret: \033[0m" << darkestSecret << std::endl;
}


static std::string truncate(const std::string &str) {
	
	if (str.length() > 10)
			return str.substr(0, 9) + ".";
		return str;
}

void Contact::displaySummary(int index) const {

	  std::cout << "|" << std::setw(10) << index << "|"
              << std::setw(10) << truncate(firstName) << "|"
              << std::setw(10) << truncate(lastName) << "|"
              << std::setw(10) << truncate(nickName) << "|\n";
}