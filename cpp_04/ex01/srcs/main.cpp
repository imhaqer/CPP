#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main() {


	std::cout << "======= Deep copy tests =======\n";

	// test default constructor
	Cat originalCat;

	originalCat.getBrain()->setIdea(0, "I want tuna!");
	originalCat.getBrain()->setIdea(1, "I want to play!");

	std::cout << "[0] " << originalCat.getBrain()->getIdea(0) << "\n";
	std::cout << "[1] " << originalCat.getBrain()->getIdea(1) << "\n";
	std::cout << "\n";


	// test copy constructor
	Cat copyCat(originalCat);
	copyCat.getBrain()->setIdea(0, "I am not the original Cat!");
	std::cout << "[0] " << copyCat.getBrain()->getIdea(0) << "\n";
	std::cout << "\n";


	// test copy assignment
	Dog original;
	Dog assignedDog = original;
	assignedDog.getBrain()->setIdea(1, "let's go for a dog walk!");
	std::cout << "[1] " << assignedDog.getBrain()->getIdea(1) << "\n";



	std::cout << "\n======= Animal Brain's tests =======\n";
	const int animalCount = 2;
	Animal* animalsArray[animalCount];

	for ( int i = 0; i < animalCount; i++) {
		if (i % 2 == 0) 
			animalsArray[i] = new Dog();
		else
			animalsArray[i] = new Cat();
	}

	for ( int i = 0; i < animalCount; i++) 
		delete animalsArray[i];
	
	std::cout << "\n\n========== Cleanup ============\n";

	return 0;

}

// int main() {
//     std::cout << "========== DEEP COPY TEST ===========\n";
    
//     // Create original cat
//     Cat original;
//     original.getBrain()->setIdea(0, "I want tuna");
//     original.getBrain()->setIdea(1, "I need a nap");
    
//     // Test copy constructor
//     Cat copy(original);
//     copy.getBrain()->setIdea(0, "I want salmon instead");
    
//     // Test assignment operator
//     Cat assigned;
//     assigned = original;
//     assigned.getBrain()->setIdea(1, "I'm not sleepy anymore");
    
//     // Verify deep copies
//     std::cout << "\nORIGINAL IDEAS:\n";
//     std::cout << "0: " << original.getBrain()->getIdea(0) << "\n";
//     std::cout << "1: " << original.getBrain()->getIdea(1) << "\n";
    
//     std::cout << "\nCOPY IDEAS:\n";
//     std::cout << "0: " << copy.getBrain()->getIdea(0) << "\n";
//     std::cout << "1: " << copy.getBrain()->getIdea(1) << "\n";
    
//     std::cout << "\nASSIGNED IDEAS:\n";
//     std::cout << "0: " << assigned.getBrain()->getIdea(0) << "\n";
//     std::cout << "1: " << assigned.getBrain()->getIdea(1) << "\n";
    
//     std::cout << "\n========== CLEANUP ===========\n";
//     return 0;
// }