#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"


//     DERIVED CLASS       //
class FragTrap : public ClapTrap {
	public:
		FragTrap();
		~FragTrap() override;
		FragTrap(const FragTrap& other);
		FragTrap(const std::string& name);
		FragTrap& operator=(const FragTrap& other);
		
		void highFivesGuys(void);
};

#endif