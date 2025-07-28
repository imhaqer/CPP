#include "FragTrap.hpp" 


FragTrap::FragTrap() : ClapTrap () {
	_name = "Unkown";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;


	std::cout << BLUE << "🛠️  Default FragTrap constructed! 🛠️\n" << RESET
		<< BOLD << " Name: " << RESET << _name
		<< BOLD << "\n Hit points: " << RESET << _hitPoints
		<< BOLD << "\n Energy points: " << RESET << _energyPoints
		<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
		std::cout << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap () {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << BLUE << "🛠️  FragTrap constructed! 🛠️\n" << RESET
	<< BOLD << " Name: " << RESET << _name
	<< BOLD << "\n Hit points: " << RESET << _hitPoints
	<< BOLD << "\n Energy points: " << RESET << _energyPoints
	<< BOLD << "\n Attack damage: " << RESET << _attackDamage << std::endl;
	std::cout << std::endl;


}

FragTrap::FragTrap(const FragTrap &other) {

	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}


FragTrap::~FragTrap()  {
	std::cout << BLUE << " 🧹 [FragTrap] " << _name << " destroyed 🧹\n" << RESET;
}


void FragTrap::highFivesGuys() {

	std::cout << " 👏 [FragTrap] " << _name << "sending a positive highFives!\n";
}