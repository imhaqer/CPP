#include "PhoneBook.hpp"
#include <limits>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

void PhoneBook::addContact() {

std::string first, last, nick, phone, secret;


std::cout << "\nEnter contact details:\n";
std::cout << "First Name: ";
std::getline(std::cin, first);
std::cout << "Last Name: ";
std::getline(std::cin, last);
std::cout << "Nickname: ";
std::getline(std::cin, nick);
std::cout << "Phone Number: ";
std::getline(std::cin, phone);
std::cout << "Darkest Secret: ";
std::getline(std::cin, secret);

contact[currentIndex].setDetails(first, last, nick, phone, secret);

currentIndex = (currentIndex + 1) % 8;
if (contactCount < 8)
    contactCount++;
}

void PhoneBook::searchContact() const{

if (contactCount == 0) {
    std::cout << "Phonebook is empty!\n";
    return ;}
std::cout << "\n|  index   |First Name| Last Name| Nickname |\n";
std::cout << "|----------|----------|----------|----------|\n";


for (int i = 0; i < contactCount; i++) {
    contact[i].displaySummary(i);
}
std::cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";
std::cout << "\nEnter index to display: ";
int index;
std::cin >> index;
std::cout << std::endl;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

if (index >= 0 && index < contactCount) {
    contact[index].displyFull();
} else {
    std::cout << "Invalid index!\n";
}

}