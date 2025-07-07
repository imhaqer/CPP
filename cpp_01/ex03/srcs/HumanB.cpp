
#include "HumanB.hpp"


HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& newWeapon)
{
		_weapon = &newWeapon;
}


void HumanB::attack(void) const 
{
	const std::string GREEN = "\033[1;32m";
	const std::string CYAN = "\033[1;36m";
	const std::string RESET = "\033[0m";
	
	if (_weapon)
		std::cout << GREEN << this->_name 
			  << RESET << " attack with their "
			  << CYAN << this->_weapon->getType() 
			  << RESET << std::endl;
	else
		std::cout << GREEN << this->_name 
				<< RESET << " has no weapon to attack with!\n";
}
