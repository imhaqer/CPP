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

Cat::Cat(const Cat& other) 
    : Animal(other), _brain(new Brain(*other._brain)) {

    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {

    if (this != &other) {
        Animal::operator=(other);
        delete _brain; 
        _brain = new Brain(*other._brain);
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