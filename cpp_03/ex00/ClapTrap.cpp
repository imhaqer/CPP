#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Unkown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "Constructor is called for " << _name << std::endl;
}

ClapTrap::~ClapTrap() {

	std::cout << "Destructor is called\n";
}

void ClapTrap::attack(const std::string& target) {

	std::cout << _name << " attacks " << target << " causing "
		<< _attackDamage << " points of damage!\n";
	

}