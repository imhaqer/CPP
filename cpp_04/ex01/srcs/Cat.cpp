#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal() {
    this->_type = type;
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}

// Animal::Animal(std::strin)