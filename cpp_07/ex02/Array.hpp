#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <exception>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;

public:
    // Default constructor: Creates an empty array
    Array() : _array(NULL), _size(0) {}

    // Constructor with size: Creates an array of n elements initialized by default
    explicit Array(unsigned int n) : _size(n)
    {
        _array = new T[_size](); // Use value initialization to zero-initialize the elements
    }

    // Copy constructor
    Array(const Array& other) : _size(other._size)
    {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            // Clean up current memory
            delete[] _array;

            // Copy new array
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
            {
                _array[i] = other._array[i];
            }
        }
        return *this;
    }

    // Destructor: Frees dynamically allocated memory
    ~Array()
    {
        delete[] _array;
    }

    // Subscript operator
    T& operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return _array[index];
    }

    // Const subscript operator for read-only access
    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return _array[index];
    }

    // Returns the size of the array
    unsigned int size() const
    {
        return _size;
    }
};

#endif