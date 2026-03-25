#include <iostream>
#include "Array.hpp"

int main()
{
    // Test 1: Create an empty array
    Array<int> arr1;
    std::cout << "Test 1: Empty Array size: " << arr1.size() << std::endl;

    // Test 2: Create an array with 5 elements
    Array<int> arr2(5);
    std::cout << "Test 2: Array size: " << arr2.size() << std::endl;

    // Initialize array elements and print
    for (unsigned int i = 0; i < arr2.size(); ++i)
    {
        arr2[i] = i + 1;  // Initialize with 1, 2, 3, 4, 5
    }

    // Print the elements
    std::cout << "Test 2: Array elements: ";
    for (unsigned int i = 0; i < arr2.size(); ++i)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // Test 3: Test Copy Constructor
    Array<int> arr3(arr2);
    std::cout << "Test 3: Copy constructor elements: ";
    for (unsigned int i = 0; i < arr3.size(); ++i)
    {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    // Test 4: Test Assignment Operator
    Array<int> arr4 = arr2;
    std::cout << "Test 4: After assignment, arr4 elements: ";
    for (unsigned int i = 0; i < arr4.size(); ++i)
    {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    // Modify arr2 and check if arr4 is independent
    arr2[0] = 100;
    std::cout << "Test 4: After modifying arr2[0], arr4 elements: ";
    for (unsigned int i = 0; i < arr4.size(); ++i)
    {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    // Test 5: Out of bounds access
    try
    {
        std::cout << "Test 5: Accessing out-of-bounds: " << arr2[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 5: Exception caught: " << e.what() << std::endl;
    }

    return 0;
}