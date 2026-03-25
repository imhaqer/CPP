#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap: exchanges the values of a and b using a temporary variable
// works with any type that supports copy/assignment
template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// min: returns the smaller of the two values
template<typename T>
const T &min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

// max: returns the larger of the two values
template<typename T>
const T &max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif
