#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation", 145, 137), target_("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
	: AForm(cpy), target_(cpy.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		AForm::operator=(src);
		target_ = src.target_;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = target_ + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (file.is_open()) {
		file << "       _-_\n";
		file << "    /~~   ~~\\\n";
		file << " /~~         ~~\\\n";
		file << "{               }\n";
		file << " \\  _-     -_  /\n";
		file << "   ~  \\\\ //  ~\n";
		file << "_- -   | | _- _\n";
		file << "  _ -  | |   -_\n";
		file << "      // \\\\\n";
		file.close();
	}
}