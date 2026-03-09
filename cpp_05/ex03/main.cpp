#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Intern someRandomIntern;

	std::cout << "=== Test: Create robotomy request ===" << std::endl;
	{
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			Bureaucrat boss("Boss", 1);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}

	std::cout << "\n=== Test: Create shrubbery creation ===" << std::endl;
	{
		AForm *scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		if (scf) {
			std::cout << *scf << std::endl;
			Bureaucrat bob("Bob", 1);
			bob.signForm(*scf);
			bob.executeForm(*scf);
			delete scf;
		}
	}

	std::cout << "\n=== Test: Create presidential pardon ===" << std::endl;
	{
		AForm *ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (ppf) {
			std::cout << *ppf << std::endl;
			Bureaucrat president("President", 1);
			president.signForm(*ppf);
			president.executeForm(*ppf);
			delete ppf;
		}
	}

	std::cout << "\n=== Test: Unknown form name ===" << std::endl;
	{
		AForm *unknown;
		unknown = someRandomIntern.makeForm("unknown form", "target");
		if (!unknown)
			std::cout << "Form was not created." << std::endl;
	}

	return 0;
}
