#include "Zombie.hpp"

int main()
{
	Zombie *zombie1;

	zombie1 = newZombie("heapZombie");
	zombie1->announce();
	delete(zombie1);
	randomChump("stackZombie");
		
	return (0);
}