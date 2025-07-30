#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main() {


	// std::cout << "======= Deep copy tests =======\n";

	// // test default constructor
	// Cat originalCat;

	// originalCat.getBrain()->setIdea(0, "I want tuna!");
	// originalCat.getBrain()->setIdea(1, "I want to play!");

	// std::cout << "[0] " << originalCat.getBrain()->getIdea(0) << "\n";
	// std::cout << "[1] " << originalCat.getBrain()->getIdea(1) << "\n";
	// std::cout << "\n";


	// // test copy constructor
	// Cat copyCat(originalCat);
	// copyCat.getBrain()->setIdea(0, "I am not the original Cat!");
	// std::cout << "[0] " << copyCat.getBrain()->getIdea(0) << "\n";
	// std::cout << "\n";


	// // test copy assignment
	// Dog original;
	// Dog assignedDog = original;
	// assignedDog.getBrain()->setIdea(1, "let's go for a dog walk!");
	// std::cout << "[1] " << assignedDog.getBrain()->getIdea(1) << "\n";



	// std::cout << "\n======= Animal Brain's tests =======\n";
	// const int animalCout = 2;
	// Animal* animalsArray[animalCout];

	// for ( int i = 0; i < animalCout; i++) {
	// 	if (i % 2 == 0) 
	// 		animalsArray[i] = new Dog();
	// 	else
	// 		animalsArray[i] = new Cat();
	// }

	// for ( int i = 0; i < animalCout; i++) 
	// 	delete animalsArray[i];
	
	// std::cout << "\n\n========== Cleanup ============\n";

	//const Animal* abstractAnimal = new Animal();
	//Animal class is now abstract and cannot be instaciated

	return 0;

}

