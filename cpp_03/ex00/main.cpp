#include "ClapTrap.hpp"

int main ()
{
	ClapTrap Bob("Bob");
	ClapTrap Nic("Nic");

	ClapTrap unkown;

	Bob.attack("Nic");
	Nic.takeDamage(3);
	calp.getDanagepoint();

	Nic.beRepaired(10);
	Bob.attack("Nic");
	Nic.takeDamage(7);


	std::cout << std::endl;
	return 0;
}

