#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"




//     DERIVED CLASS       //
class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		~ScavTrap() override;
		ScavTrap(const ScavTrap& other);
		ScavTrap(const std::string& name);
		ScavTrap& operator=(const ScavTrap& other);
		
		void attack(const std::string& target) override;
		void guardGate();
};


#endif