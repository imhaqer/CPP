#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

const std::string GREEN = "\033[1;32m";
const std::string RESET = "\033[0m";
const std::string BOLD =  "\033[1m";
const std::string CYAN  = "\033[1;36m";
const std::string YELLOW  = "\033[1;33m";

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
};


#endif
