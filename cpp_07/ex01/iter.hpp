#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for std::size_t

// iter: applies a function to every element of an array
//
// T is deduced from the array pointer — if the array is const int*,
// then T becomes const int, so the function receives a const reference.
// This naturally handles both const and non-const arrays without
// needing two separate overloads.
//
// Parameters:
//   arr  - pointer to the first element of the array
//   len  - number of elements (passed as const so it can't be modified)
//   func - callable that accepts a single element (by ref or const ref)
template<typename T, typename F>
void iter(T *arr, const std::size_t len, F func)
{
    for (std::size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif
