#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "=== Test ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test execute without signing ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		boss.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test grade too low to sign ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Zaphod");
		intern.signForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test grade too low to execute ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("garden");
		boss.signForm(shrub);
		intern.executeForm(shrub);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
