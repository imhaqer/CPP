#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

// ScalarConverter: detects the type of a C++ literal and prints
// its value as char, int, float, and double.
//
// The class is non-instantiable (private constructor/destructor).
// All work happens through the single static method convert().
class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

public:
    static void convert(const std::string &input);
};

#endif
