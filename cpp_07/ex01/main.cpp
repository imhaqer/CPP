#include <iostream>
#include <string>
#include "iter.hpp"

// --- helper functions used as the third argument to iter ---

// prints any element followed by a newline
template<typename T>
void printElem(const T &elem)
{
    std::cout << elem << std::endl;
}

// doubles an integer in-place (requires non-const reference)
void doubleIt(int &n)
{
    n *= 2;
}

// converts a char to uppercase in-place
void toUpper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

int main(void)
{
    // --- int array: print each element ---
    int nums[] = {1, 2, 3, 4, 5};
    std::cout << "Original ints:" << std::endl;
    ::iter(nums, 5, printElem<int>);

    // --- int array: double each element (modifying, non-const) ---
    ::iter(nums, 5, doubleIt);
    std::cout << "After doubling:" << std::endl;
    ::iter(nums, 5, printElem<int>);

    // --- string array: print each element ---
    std::string words[] = {"hello", "world", "templates"};
    std::cout << "Strings:" << std::endl;
    ::iter(words, 3, printElem<std::string>);

    // --- const array: only const operations allowed ---
    const int consts[] = {10, 20, 30};
    std::cout << "Const ints:" << std::endl;
    ::iter(consts, 3, printElem<int>);

    // --- char array: modify each char in-place ---
    char letters[] = {'a', 'b', 'c', 'd'};
    ::iter(letters, 4, toUpper);
    std::cout << "Uppercased chars:" << std::endl;
    ::iter(letters, 4, printElem<char>);

    // --- edge case: zero-length array (nothing should happen) ---
    int empty[] = {99};
    std::cout << "Zero-length iter (no output expected):" << std::endl;
    ::iter(empty, 0, printElem<int>);
    std::cout << "Done." << std::endl;

    return 0;
}
