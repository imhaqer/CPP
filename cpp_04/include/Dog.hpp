#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal {
    public:
        Dog();
        ~Dog() override;
        Dog(const std::string& type);
        Dog& operator=(const Dog& other);
        Dog(const Dog& other);
    
        void makeSound() const override;

};

#endif