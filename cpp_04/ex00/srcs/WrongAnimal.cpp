#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    _type = "Unkown Animal";
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Wrong animal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    *this = other;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->_type = other._type;

     std::cout << "WrongAnimal assignment operator called" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound\n";
}