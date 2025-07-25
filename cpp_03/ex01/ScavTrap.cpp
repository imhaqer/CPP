#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap () {
	_name = "Unkown";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;


	std::cout << BLUE << "🛠️  Default ScavTrap constructed! 🛠️\n" << RESET
		<< BOLD << " Name: " << RESET << _name
		<< BOLD << "\n Hit points: " << RESET << _hitPoints
		<< BOLD << "\n Energy points: " << RESET << _energyPoints
		<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
		std::cout << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap () {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << BLUE << "🛠️  Default ScavTrap constructed! 🛠️\n" << RESET
	<< BOLD << " Name: " << RESET << _name
	<< BOLD << "\n Hit points: " << RESET << _hitPoints
	<< BOLD << "\n Energy points: " << RESET << _energyPoints
	<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
	std::cout << std::endl;


}

ScavTrap::ScavTrap(const ScavTrap &other) {

	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}


ScavTrap::~ScavTrap()  {
	std::cout << BLUE << " 🧹 [ScavTrap] " << _name << " destroyed 🧹\n" << RESET;
}


void ScavTrap::attack(const std::string& target)  {
  if (_hitPoints > 0 || _energyPoints > 0)
	{
		std::cout << " 🗡️ [ScavTrap] " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
		_energyPoints -= 1;
		std::cout  << " ⚠️ [ScavTrap] " << _name << " loses 1 energy points. " << _energyPoints << " energy points left.\n";
	}
	else
		std::cout << " ❌ [ScavTrap] " << _name << " can't attack, not enough energy points!\n" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << " 🛡️ [ScavTrap] " << _name << " entered Gate Keeper mode!\n";
}