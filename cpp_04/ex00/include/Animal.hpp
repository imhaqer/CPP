#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal {
    protected:
        std::string _type;

    public:
        Animal();  // Default constructor
        virtual ~Animal();  // Virtual destructor
        Animal& operator=(const Animal& other);
        Animal(const Animal& other);

        std::string getType() const;
        virtual void makeSound() const;
      
};

#endif