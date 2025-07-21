#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {

    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& obj) : _rawValue(obj._rawValue) {

    std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) {

    std::cout << "Int constructor called\n";
    _rawValue = value << _fractionalBits;
    
}

Fixed::Fixed(const float value) {

    std::cout << "Float constructor called\n";
    _rawValue = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& obj) {

    std::cout << "Copy assignment operator called\n";
    if (this != &obj)
        this->setRawBits(obj.getRawBits());
    return *this;
}

Fixed::~Fixed() {

    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {

    return (this->_rawValue);
}

void Fixed::setRawBits(int const raw) {

    this->_rawValue = raw;
}

float Fixed::toFloat() const {

    return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {

    return _rawValue >>  _fractionalBits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}