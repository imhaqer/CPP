#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {


    Animal *animal = new Dog();
    // const Animal* meta = new Animal();
    animal->makeSound();
   std::cout << animal->getType() << " " << std::endl;
}