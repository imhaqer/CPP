#include "Contact.hpp"

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

	std::cout << std::endl;
	std::cout << "\033[1mFirst Name: \033[0m" << firstName << std::endl;
	std::cout << "\033[1mLast Name: \033[0m" << lastName << std::endl;
	std::cout << "\033[1mNickname: \033[0m" << nickName<< std::endl;
	std::cout << "\033[1mPhone Number: \033[0m" << phoneNumner << std::endl;
	std::cout << "\033[1mDarkest Secret: \033[0m" << darkestSecret << std::endl;
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