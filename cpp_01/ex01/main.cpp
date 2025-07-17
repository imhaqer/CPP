#include "Zombie.hpp"

int main()
{
	const int N = 10;
	const std::string hordeName = "zombieHorde";

	Zombie* horde = zombieHorde(N, hordeName);
	if (!horde) return 1;
	for (int i = 0; i < N; i++){
		std::cout << "[" << i << "]"; horde[i].announce();
	}
	for (int i = 0; i < N; i++) {
        std::cout << "[" << i << "]"; horde[i].~Zombie();
    }
 	operator delete[](horde);

	return 0;
}