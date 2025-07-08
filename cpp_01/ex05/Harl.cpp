#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void Harl::_debug()
{
	std::cout << "\033[1;32m[ DEBUG ]\033[0m I love having extra bacon for my " 
				"7XL-double-cheese-triple-pickle-special-\n"
				"ketchup burger. I really do!\n";
}

void Harl::_info()
{
	std::cout << "\033[1;31m[ INFO ]\033[0m I cannot believe adding" 
			"extra bacon costs more money.\nYou didn’t put enough "
			"bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_warning()
{
	std::cout << "\033[1;34m[ WARNING ]\033[0m I think I deserve to have " 
			"some extra bacon for free.\nI’ve been coming for years "
			 "whereas you started working here since last month.\n";
}

void Harl::_error()
{
	std::cout << "\033[1;36m[ ERROR ]\033[0m This is unacceptable! I want to speak to the manager now.\n";
}	

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};  //array of str

	void (Harl::*complains[])() = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};


	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*complains[i])();
			return ;
		}
			
	}
}
