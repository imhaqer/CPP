#include "Zombie.hpp"

int main()
{

	Zombie *horde;
	int N = 5;

	horde = zombieHorde(N, "zombieHorde");

	for (int i = 0; i < N; i++)
	{
		//horde[i] = horde->announce();
		// std::cout <<"Index " << i << ": ";
		// horde[i].announce();

		std::cout << "[" << i << "]"; horde[i].announce();
		// std::cout << "Zombie " << i << " address: " << &horde[i] << "\n";
		
	}
	// delete[] horde;
	for (int i = 0; i < N; i++) {
        horde[i].~Zombie();
    }
 	operator delete[](horde);

	return (0);
}