#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
    // --- default constructor: empty array ---
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // --- size constructor: 5 ints, value-initialized to 0 ---
    Array<int> ints(5);
    std::cout << "Int array size: " << ints.size() << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = static_cast<int>(i * 10);

    std::cout << "Int array contents:";
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << " " << ints[i];
    std::cout << std::endl;

    // --- copy constructor: deep copy ---
    Array<int> copy(ints);
    copy[0] = 999;  // modifying copy should NOT affect original
    std::cout << "Original[0] after copy was modified: " << ints[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    // --- assignment operator ---
    Array<int> assigned;
    assigned = ints;
    assigned[1] = 888;
    std::cout << "Original[1] after assigned was modified: " << ints[1] << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;

    // --- self-assignment (should be safe) ---
    ints = ints;
    std::cout << "After self-assign, ints[0]: " << ints[0] << std::endl;

    // --- string array ---
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "!";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;

    // --- out of bounds access: should throw ---
    std::cout << "Testing out-of-bounds access:" << std::endl;
    try
    {
        ints[100] = 0;
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // --- access on empty array: should throw ---
    try
    {
        empty[0] = 0;
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught expected exception on empty: " << e.what() << std::endl;
    }

    // --- const array: read-only access ---
    const Array<int> constArr(ints);
    std::cout << "Const array[2]: " << constArr[2] << std::endl;
    try
    {
        constArr[50];
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught expected exception on const: " << e.what() << std::endl;
    }

    return 0;
}
