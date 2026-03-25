#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
   // Create a Data object on the heap with some values
    Data *original = new(std::nothrow) Data;  // Allocate memory with error check

    // Check if allocation was successful
    if (original == nullptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;  // Exit the program with an error code
    }
    original->id    = 42;
    original->label = "hello";
    original->value = 3.14;

    std::cout << "Original pointer:    " << original << std::endl;
    std::cout << "Original id:         " << original->id << std::endl;
    std::cout << "Original label:      " << original->label << std::endl;
    std::cout << "Original value:      " << original->value << std::endl;

    // Serialize: pointer -> integer
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "Serialized integer:  " << raw << std::endl;

    // Deserialize: integer -> pointer
    Data *recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer:   " << recovered << std::endl;
    std::cout << "Recovered id:        " << recovered->id << std::endl;
    std::cout << "Recovered label:     " << recovered->label << std::endl;
    std::cout << "Recovered value:     " << recovered->value << std::endl;

    // The recovered pointer must be the same as the original
    if (recovered == original)
        std::cout << "Pointers match: OK" << std::endl;
    else
        std::cout << "Pointers DO NOT match: ERROR" << std::endl;

    // --- edge case: NULL pointer ---
    Data       *nullPtr = NULL;
    uintptr_t   rawNull = Serializer::serialize(nullPtr);
    Data       *backNull = Serializer::deserialize(rawNull);
    std::cout << "NULL serialize/deserialize: "
              << (backNull == NULL ? "OK" : "ERROR") << std::endl;

    delete original;
    return 0;
}
