#include "Serializer.hpp"

// reinterpret_cast<uintptr_t>: take the pointer's address value
// and store it as an unsigned integer of the same size as a pointer.
// This is explicitly what reinterpret_cast is designed for.
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// reinterpret_cast<Data *>: take the raw integer and treat it as
// a pointer to Data. This round-trips correctly because we used
// uintptr_t which is guaranteed to be wide enough to hold a pointer.
Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
