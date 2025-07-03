#include "Zombie.hpp"

int main()
{

	Zombie *horde;
	int N = 5;

	horde = zombieHorde(N, "Horde");

	for (int i = 0; i < N; i++)
	{
		//horde[i] = horde->announce();
		std::cout <<"Index " << i << ": ";
		horde[i].announce();
		
	}






	return (0);
}