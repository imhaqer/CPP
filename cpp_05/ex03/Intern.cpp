#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy) {
	(void)cpy;
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*creators[])(const std::string &) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			AForm *form = (this->*creators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create form \"" << formName
			  << "\": unknown form name." << std::endl;
	return NULL;
}
