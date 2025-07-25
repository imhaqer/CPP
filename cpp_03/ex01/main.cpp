#include "ScavTrap.hpp"

int main ()
{
	std::cout<< "\n\n";



	std::cout << BOLD << "==== 1. Base Pointer to Derived (polymoriphism) =====\n" << RESET;



	ClapTrap* PolyBot = new ScavTrap("PolyBot"); 
	PolyBot->attack("Target");  // uses Scav trap attack()

	std::cout << BOLD <<  "\n======= Virtual Destructor Behavior =========\n" << RESET;
	delete PolyBot;   // virtual destructor 


	
	
	
	
	std::cout << BOLD << "\n\n==== 2. Direct Object Test (No Polymorphism) ====\n " << RESET;

	ClapTrap normalBot("Bot1");
	ScavTrap normalBot2("Bot2");

	normalBot.attack("Target");
	normalBot2.attack("Enemy");


	std::cout << BOLD << "\n======= Deleting Non-Polymorphic Object =========\n" << RESET;
	

	
	return 0;
}