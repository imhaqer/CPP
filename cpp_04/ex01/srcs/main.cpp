#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {


    WrongAnimal	*Bad = new WrongAnimal();
	Dog		*dog = new Dog();

	std::cout << "Wrong Cat: "<< Bad->getType() << " " << std::endl;
	std::cout << "Dog: "<< dog->getType() << " " << std::endl;

	Bad->makeSound();
	dog->makeSound();
	// delete unknown;

	Bad = new WrongCat();
	Bad->makeSound();
	delete dog;
	// delete unknown;
}