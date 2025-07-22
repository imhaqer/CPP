#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unkown"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor is called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor is called\n";
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > amount) {
		_hitPoints -= amount;
	}
	else {
		_hitPoints = 0;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage,"
		"now has " << _hitPoints << " hit points!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't repair!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points,"
		"now has " << _hitPoints << " hit points!" << std::endl;
}
