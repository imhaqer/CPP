#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	// this->_name = name;
	std::cout << _name << " got created.\n";
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << _name << " got destroyed.\n";
}
