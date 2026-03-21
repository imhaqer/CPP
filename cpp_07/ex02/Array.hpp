#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>  // for std::out_of_range
#include <cstddef>    // for std::size_t

// Array: a generic fixed-size array wrapper
// Follows Orthodox Canonical Form (default ctor, copy ctor, copy assign, dtor)
template<typename T>
class Array
{
private:
    T            *_data;  // heap-allocated array of T
    unsigned int  _size;  // number of elements

public:
    // Default constructor: creates an empty array (size 0, no allocation)
    Array();

    // Size constructor: allocates n elements, value-initialized via new T[n]()
    // Value-initialization zero-initializes POD types (int -> 0, etc.)
    Array(unsigned int n);

    // Copy constructor: deep-copies every element from other
    Array(const Array &other);

    // Assignment operator: deep copy, handles self-assignment safely
    Array &operator=(const Array &other);

    // Destructor: releases the heap memory
    ~Array();

    // Subscript operator (non-const): allows reading and writing arr[i]
    // Throws std::out_of_range if index >= size
    T &operator[](unsigned int index);

    // Subscript operator (const): allows reading from a const Array
    // Throws std::out_of_range if index >= size
    const T &operator[](unsigned int index) const;

    // size(): returns the number of elements; never modifies the object
    unsigned int size() const;
};

// Template implementations must be visible at the point of instantiation.
// We keep them in a .tpp file and include it here.
#include "Array.tpp"

#endif
