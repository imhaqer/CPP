#include "ClapTrap.hpp"

int main ()
{
	


	ClapTrap Bob("Bob");
	ClapTrap Nic("Nic");
	ClapTrap unkown;


	std::cout << BOLD << "\n               Aaaaand... OPEN!\n\n" << RESET;

	
	Bob.attack("Nic");
	Nic.takeDamage(3);

	Nic.beRepaired(10);
	Bob.attack("Nic");
	Nic.takeDamage(7);


	std::cout << std::endl;
	return 0;
}

