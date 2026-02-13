#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
	: AForm(cpy), target_(cpy.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		AForm::operator=(src);
		target_ = src.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
	std::cout << "* drilling noises * Brrrrrrr..." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << target_ << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << target_ << " failed." << std::endl;
}
