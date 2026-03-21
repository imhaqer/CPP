// Array.tpp — template method definitions
// Included at the bottom of Array.hpp, NOT compiled separately.

// Default constructor: size 0, no memory allocated
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Size constructor: allocate n elements, value-initialized
// new T[n]() calls the default constructor for class types,
// and zero-initializes built-in types (int, float, etc.)
template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

// Copy constructor: allocate a fresh block and copy each element
template<typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(0)
{
    *this = other;
}

// Assignment operator: free old data, allocate and copy from other
template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)  // guard against self-assignment
        return *this;

    delete[] _data;  // release current storage

    _size = other._size;
    if (_size == 0)
    {
        _data = NULL;
        return *this;
    }

    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];

    return *this;
}

// Destructor: release the heap-allocated array
template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

// Non-const subscript: allows modification of elements
template<typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _data[index];
}

// Const subscript: read-only access for const Array objects
template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _data[index];
}

// size(): returns element count without modifying the object
template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
