#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>



class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumner;
	std::string darkestSecret;

public:
	Contact();
	void setDetails(const std::string &first, const std::string &last,
		const std::string &nick, const std::string &phone,
		const std::string &secret);
	void displyFull() const;
};

#endif