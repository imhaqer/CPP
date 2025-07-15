#include "Zombie.hpp"

Zombie *newZombie(std::string name )
{
	Zombie *zombie = new(std::nothrow) Zombie(name);
	if (!zombie) {
		std::cerr << "Error: memory allocation failed.\n";
		return nullptr;
	}
	return(zombie);
}