#ifndef HUMAN_A
#define HUMAN_A
 
#include <string>
#include "Weapon.hpp"


class HumanA {
	private:
		const std::string _name;
		const Weapon&  _weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
		void attack() const; 
};

#endif