#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}


void HumanA::attack(void) const 
{
	const std::string GREEN = "\033[1;32m";
	const std::string CYAN = "\033[1;36m";
	const std::string RESET = "\033[0m";

	std::cout << GREEN << this->_name 
			  << RESET << " attack with their "
			  << CYAN << this->_weapon.getType() 
			  << RESET << std::endl;
}

