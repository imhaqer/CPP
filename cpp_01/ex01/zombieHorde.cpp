#include "Zombie.hpp"


Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];  // requires default constructor

	for (int i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);
	}
	return (horde);
}