#include "../include/Brain.hpp"

Brain::Brain() {

	std::cout << "Brain default constructor called!\n";
}

Brain::~Brain() {

    std::cout << "Brain destroyed!\n";	
}

Brain::Brain(const Brain& other) {
    
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {

    std::cout << "Brain copy assignment operator called" << std::endl;
    
    if (this == &other)
        return *this;
    
    // deep copy of array elements
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    
    return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

const std::string& Brain::getIdea(int index) const {

    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    throw std::out_of_range("Invalid idea index");
}
