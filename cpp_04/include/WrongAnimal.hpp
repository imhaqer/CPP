#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        ~ WrongAnimal();
        WrongAnimal& operator=(const  WrongAnimal& other);
        WrongAnimal(const  WrongAnimal& other);

        std::string getType() const;
        void makeSound() const;
      
};

#endif