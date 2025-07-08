#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void Harl::_debug()
{
	std::cout << "[ DEBUG ] I love having extra bacon for my" 
				"7XL-double-cheese-triple-pickle-special-"
				"ketchup burger. I really do!\n";
}

void Harl::_info()
{
	std::cout << "[ INFO ] I cannot believe adding" 
			"extra bacon costs more money. You didn’t put enough"
			"bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_warning()
{
	std::cout << "[ WARNING ] I think I deserve to have" 
			"some extra bacon for free. I’ve been coming for years"
			 "whereas you started working here since last month.\n";
}

void Harl::_error()
{
	std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now.\n";
}	

void Harl::complain(std::string level)
{

}
