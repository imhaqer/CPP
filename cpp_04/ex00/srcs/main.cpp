#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main() {


	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();


	std::cout << "======== Generic Animal ===============" << std::endl;
	Animal unkown;
	Animal Owl(unkown); // Animal copy constructor

	std::cout << "Animal type: "<< unkown.getType() << " " << std::endl;
	std::cout << "Sound: ";
	unkown.makeSound();

	std::cout << "\n======== Wrong Animal ===============" << std::endl;
	WrongAnimal	*Bad = new WrongAnimal(); 
	
	WrongAnimal mouse;  //wrong animal default constructor
	WrongAnimal terribleAnimal(mouse);  // Wrong Animal copy constructor
	
	std::cout << "Animal type: "<< Bad->getType() << " " << std::endl;
	std::cout << "Sound: ";
	Bad->makeSound();
	delete Bad;
	std::cout << std::endl;


	std::cout << "======== Wrong Cat Animal ===============" << std::endl;
	WrongAnimal	*badCat = new WrongCat(); 
	
	std::cout << "Animal type: "<< badCat->getType() << " " << std::endl;
	std::cout << "Sound: ";
	badCat->makeSound();
	delete badCat;
	std::cout << std::endl;

	
	std::cout << "======== Dog Animal ===============" << std::endl;
	
	Animal  *dog = new Dog();
	std::cout << "Animal type: "<< dog->getType() << " " << std::endl;
	std::cout << "Sound: ";
	dog->makeSound();
	delete dog;
	
	std::cout << "\n\n======== Cat Animal ===============" << std::endl;
	Animal  *cat = new Cat();
	std::cout << "Animal type: "<< cat->getType() << " " << std::endl;
	std::cout << "Sound: ";
	dog->makeSound();
	delete cat;

	std::cout << "\n\n";

	return 0;
	
}