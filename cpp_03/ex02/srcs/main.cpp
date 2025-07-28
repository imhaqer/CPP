#include "FragTrap.hpp"

int main ()
{
	std::cout<< "\n\n";



	std::cout << BOLD << "==== 1. Base Pointer to Derived (polymoriphism) =====\n" << RESET;



	ClapTrap* Bot1 = new FragTrap("Bot1");
	Bot1->attack("Target");  // uses FragtTap attack()

	std::cout << BOLD <<  "\n======= Virtual Destructor Behavior =========\n" << RESET;
	delete Bot1;   // virtual destructor 


	
	
	
	
	std::cout << BOLD << "\n\n==== 2. Direct Object Test (No Polymorphism) ====\n " << RESET;

	ClapTrap normalBot("Bot1");
	FragTrap normalBot2("Bot2");

	normalBot.attack("Target");
	normalBot2.attack("Enemy");
	normalBot2.highFivesGuys();


	std::cout << BOLD << "\n======= Deleting Non-Polymorphic Object =========\n" << RESET;
	



	return 0;
}