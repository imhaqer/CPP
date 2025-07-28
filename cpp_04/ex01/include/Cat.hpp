#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *_brain;
    public:
        Cat();
        ~Cat() override;
        Cat(const std::string& type);
        Cat& operator=(const Cat& other);
        Cat(const Cat& other);

        void makeSound() const override;
        Brain* getBrain() const;
};

#endif