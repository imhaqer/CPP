#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target) const;

	private:
		AForm *createShrubbery(const std::string &target) const;
		AForm *createRobotomy(const std::string &target) const;
		AForm *createPresidential(const std::string &target) const;
};

#endif
