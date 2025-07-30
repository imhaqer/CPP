#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal {
    private:
        Brain *_brain;
    public:
        Dog();
        ~Dog();
        Dog& operator=(const Dog& other);
        Dog(const Dog& other);
    
        void makeSound() const override;
        Brain* getBrain() const;

};

#endif