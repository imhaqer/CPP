#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) 
{
	std::cout << _name << " got created.\n";
}
Zombie::~Zombie()
{
	std::cout << _name << " got destroyed.\n";
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}