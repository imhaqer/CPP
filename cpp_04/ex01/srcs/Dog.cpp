#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal() {
    this->_type = type;
    this->_brain = new Brain();
    std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {

    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {               // 1. Check for self-assignment
        Animal::operator=(other);       // 2. Copy base class part
        delete _brain;                   // 3. Clean up old resources
        _brain = new Brain(*other._brain);// 4. Deep copy
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}