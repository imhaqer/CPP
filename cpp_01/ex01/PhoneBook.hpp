#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook {
private:
    Contact     contact[8];
    int     currentIndex;
    int     contactCount;

public:
    PhoneBook();
    void    addContact();
    void    searchContact() const;
};

#endif