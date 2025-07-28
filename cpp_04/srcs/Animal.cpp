#include "Animal.hpp"

Animal::Animal() {
    _type = "Unkown Animal";
    std::cout << "Animal default constructor called\n";
}

Animal::~Animal(){
    std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal& other){
    *this = other;
}

Animal &Animal::operator=(const Animal& other) {
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << "Generic animal sound\n";
}