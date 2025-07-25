#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Unkown"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << GREEN << "🛠️  ClapTrap Constructed! 🛠️\n" << RESET
		<< BOLD << " Name: " << RESET << _name
		<< BOLD << "\n Hit points: " << RESET << _hitPoints
		<< BOLD << "\n Energy points: " << RESET << _energyPoints
		<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
		std::cout << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "🛠️  ClapTrap Constructed! 🛠️\n" << RESET
		<< BOLD << " Name: " << RESET << _name
		<< BOLD << "\n Hit points: " << RESET << _hitPoints
		<< BOLD << "\n Energy points: " << RESET << _energyPoints
		<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
		std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD << " 🧹 ClapTrap " << _name << " destroyed 🧹\n" << RESET;
}


void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 || _energyPoints > 0)
	{
		std::cout << " 🗡️  ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
		_energyPoints -= 1;
		std::cout  << " ⚠️  ClapTrap " << _name << " loses 1 energy points. " << _energyPoints << " energy points left.\n\n";
	}
	else
		std::cout << " ❌ ClapTrap " << _name << " can't attack, not enough energy points!\n" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
	if (_hitPoints == 0) {
		std::cout << " 🤕 ClapTrap " << _name << " is already out of hit points, cannot take more damage!\n";
		return ;
	}

	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << " 💢 ClapTrap " << _name << " takes " << amount << " hit damage! "<< _hitPoints << " hit points left.\n";
	if (_hitPoints == 0 )
		 std::cout << "😔 ClapTrap " << _name << " has been defeated!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0) {
		std::cout << _name << " can't repair, not enough energy points!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << " 🔧 ClapTrap " << _name << " repairs itself for " << amount << " hit points, "
		"now has " << _hitPoints << " hit points!" << std::endl;
	_energyPoints--;
	std::cout << " ⚠️  ClapTrap " << _name << " loses one energy points, now it has " << _energyPoints << " energy points left!\n";
}
