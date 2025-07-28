#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat() override;
        Cat(const std::string& type);
        Cat& operator=(const Cat& other);
        Cat(const Cat& other);

        void makeSound() const override;
};

#endif