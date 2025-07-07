
#include "HumanB.hpp"


HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& newWeapon)
{
		_weapon = &newWeapon;
}


void HumanB::attack(void) const 
{
	if (_weapon)
		std::cout << this->_name << " attacking with their " 
			<< this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have a weapon to attack with!\n";
}
