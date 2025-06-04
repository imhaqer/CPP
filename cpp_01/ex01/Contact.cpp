#include "Contact.hpp"
#include <iostream>


void Contact::setDetails(const std::string &first, const std::string &last,
		const std::string &nick, const std::string &phone,
		const std::string &secret) {
	
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumner = phone;
	darkestSecret = secret;
}

void Contact::displyFull() const {

	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName<< std::endl;
	std::cout << "Phone Number: " << phoneNumner << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}