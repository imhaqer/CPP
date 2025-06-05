#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact() {}

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

void Contact::displaySummary(int index) const {
	std::cout << "|" << std::setw(10) << index << "|";

	auto truncate = [](std::string str) {
		if (str.length() > 10)
			return str.substr(0, 9) + ".";
		return str;
	};

	std::cout << std::setw(10) << truncate(firstName) << "|";
    std::cout << std::setw(10) << truncate(lastName) << "|";
    std::cout << std::setw(10) << truncate(nickName) << "|" << std::endl;
}