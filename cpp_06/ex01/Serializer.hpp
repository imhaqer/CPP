#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>  // uintptr_t (C99/C++98 compatible header)
#include "Data.hpp"

// Serializer: converts between a Data pointer and an integer.
//
// This demonstrates reinterpret_cast — the cast that treats the
// raw bit pattern of a pointer as an integer (and back).
// The class is non-instantiable (all methods are static).
class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();

public:
    // serialize: turn a pointer into an unsigned integer of the same width.
    // reinterpret_cast is the right tool here — we're not changing the value,
    // just telling the compiler to see the same bits as a different type.
    static uintptr_t serialize(Data *ptr);

    // deserialize: turn the integer back into a pointer.
    // Only safe if the value came from serialize() in the first place.
    static Data *deserialize(uintptr_t raw);
};

#endif
