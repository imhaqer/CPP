#include "../include/Cat.hpp"


Cat::Cat() : Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
    
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {

    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {

    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {

    if (this != &other) {               // 1. Check for self-assignment
        Animal::operator=(other);       // 2. Copy base class part
        delete _brain;                   // 3. Clean up old resources
        _brain = new Brain(*other._brain);// 4. Deep copy
    }
    
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}