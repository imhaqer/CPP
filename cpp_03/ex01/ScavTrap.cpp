#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(), _name(name), _hitPoints(100),
	_energyPoints(50), _attackDamage(20)
{
	std::cout << "Constructor is called for " << _name << std::endl;
}