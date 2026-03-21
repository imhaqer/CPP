#ifndef DATA_HPP
#define DATA_HPP

#include <string>

// Data: a plain struct with several members.
// The subject requires it to be non-empty (have at least one data member).
struct Data
{
    int         id;
    std::string label;
    double      value;
};

#endif
