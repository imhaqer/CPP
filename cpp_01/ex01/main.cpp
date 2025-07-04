#include "Zombie.hpp"

int main()
{
	const int N = 5;
	const std::string hordeName = "zombieHorde";

	Zombie* horde = zombieHorde(N, hordeName);
	
	for (int i = 0; i < N; i++){
		std::cout << "[" << i << "]"; horde[i].announce();
	}
	for (int i = 0; i < N; i++) {
        std::cout << "[" << i << "]"; horde[i].~Zombie();
    }
 	operator delete[](horde);

	return 0;
}