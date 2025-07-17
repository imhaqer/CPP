#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {

    std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {

    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& obj) : _rawValue(obj._rawValue) {

    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& obj) {

    std::cout << "Copy assignment operator called\n";
    if (this != &obj)
        this->setRawBits(obj.getRawBits());
    return *this;
        

}
int Fixed::getRawBits() const {

    std::cout << "getRawBits() member function called\n";
    return (this->_rawValue);
}

void Fixed::setRawBits(int const raw) {

    this->_rawValue = raw;
}