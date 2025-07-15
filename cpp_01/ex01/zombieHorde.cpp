#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{

	void* rawMemory = operator new[](N * sizeof(Zombie), std::nothrow);

	if (!rawMemory) {
		std::cerr << "Error: memory allocation failed.\n";
		return nullptr;
	}

	Zombie* zombieHorde = static_cast<Zombie*>(rawMemory);

	for (int i = 0; i < N; i++) {
		new (&zombieHorde[i]) Zombie(name);
	}

	return zombieHorde;
}