#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int	_hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getAttackDamage();
};


#endif


// ClapTrap::ClapTrap() : _name("Unkown"), _hitPoints(10), _energyPoints(10),
// 	_attackDamage(0)
// {
// 	std::cout << GREEN << "🛠️  ClapTrap Constructed! 🛠️\n" << RESET
// 		<< BOLD << "Name: " << RESET << _name
// 		<< BOLD << "\nHit points: " << RESET << _hitPoints
// 		<< BOLD << "\nEnergy points: " << RESET << _energyPoints
// 		<< BOLD << "\nAttack damage: " << RESET << _attackDamage << std::endl;
// 		std::cout << std::endl;
// }

// ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
// 	_energyPoints(10), _attackDamage(0)
// {
// 	std::cout << GREEN << "🛠️  ClapTrap Constructed! 🛠️\n" << RESET
// 		<< BOLD << "Name: " << RESET << _name
// 		<< BOLD << "\nHit points: " << RESET << _hitPoints
// 		<< BOLD << "\nEnergy points: " << RESET << _energyPoints
// 		<< BOLD << "\nAttack damage: " << RESET << _attackDamage << std::endl;
// 		std::cout << std::endl;
// }