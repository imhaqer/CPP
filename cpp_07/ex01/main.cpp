#include <iostream>
#include <string>
#include <cctype>  
#include "iter.hpp"

// --- Helper functions used as the third argument to iter ---

// Prints any element followed by a newline
template<typename T>
void printElem(const T &elem)
{
    std::cout << elem << std::endl;
}

// Doubles an integer in-place (requires non-const reference)
void doubleIt(int &n)
{
    n *= 2;
}

// Converts a char to uppercase in-place
void toUpper(char &c)
{
    c = std::toupper(c);
}


int main(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Original ints:" << std::endl;
    int nums[] = {1, 2, 3, 4, 5};
    ::iter(nums, 5, printElem<int>); // Print original integers

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "After doubling each integer:" << std::endl;
    ::iter(nums, 5, doubleIt); // Double each number in array
    ::iter(nums, 5, printElem<int>); // Print modified integers

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "Printing strings:" << std::endl;
    std::string words[] = {"hello", "world", "templates"};
    ::iter(words, 3, printElem<std::string>); // Print each string

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "Const ints (read-only):" << std::endl;
    const int consts[] = {10, 20, 30};
    ::iter(consts, 3, printElem<int>); // Print const array (no modifications allowed)

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "Uppercasing chars:" << std::endl;
    char letters[] = {'a', 'b', 'c', 'd'};
    ::iter(letters, 4, toUpper); // Convert chars to uppercase
    ::iter(letters, 4, printElem<char>); // Print uppercase chars

    std::cout << "\n---------------------------------" << std::endl;
    std::cout << "Zero-length array (no output expected):" << std::endl;
    int empty[] = {99};
    ::iter(empty, 0, printElem<int>); // Edge case: empty array
    
    return 0;
}