#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // std::find
#include <stdexcept>  // std::runtime_error

// easyfind: searches a container T (of ints) for the first occurrence of val.
//
// Returns an iterator pointing to the found element.
// Throws std::runtime_error if the value is not in the container.
//
// T must be a sequence container of integers (vector, list, deque, etc.).
// Associative containers (map, set) are not handled as per the subject.
template<typename T>
typename T::iterator easyfind(T &container, int val)
{
    // std::find scans from begin to end and returns end() if not found
    typename T::iterator it = std::find(container.begin(), container.end(), val);

    if (it == container.end())
        throw std::runtime_error("easyfind: value not found in container");

    return it;
}

// Const overload: allows searching in const containers
template<typename T>
typename T::const_iterator easyfind(const T &container, int val)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), val);

    if (it == container.end())
        throw std::runtime_error("easyfind: value not found in container");

    return it;
}

#endif
