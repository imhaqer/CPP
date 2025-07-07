#ifndef HUMAN_B
#define HUMAN_B
 
#include <string>
#include "Weapon.hpp"


class HumanB {
	private:
		const std::string _name;
		const Weapon*  _weapon;
	public:
		HumanB(const std::string& name);
		~HumanB();
		void setWeapon(Weapon &newWeapon);
		void attack() const; 
};

#endif