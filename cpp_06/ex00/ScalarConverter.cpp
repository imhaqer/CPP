#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>    // std::fixed, std::setprecision
#include <limits>     // std::numeric_limits
#include <cmath>      // std::isnan, std::isinf, fmod
#include <cstdlib>    // strtod
#include <cctype>     // std::isprint

// The four types we can detect from the string
enum LiteralType { CHAR_LIT, INT_LIT, FLOAT_LIT, DOUBLE_LIT, PSEUDO_LIT };

// detectType: inspect the string and decide what kind of literal it is.
// Order matters: pseudo-literals and char literals are checked first
// before we fall back to numeric detection.
static LiteralType detectType(const std::string &s)
{
    // pseudo-literals: nan, +inf, -inf and their float variants
    if (s == "nan" || s == "+inf" || s == "-inf" ||
        s == "nanf" || s == "+inff" || s == "-inff")
        return PSEUDO_LIT;

    // char literal: exactly three characters 'x'
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return CHAR_LIT;

    // float literal: ends in 'f' AND contains a decimal point
    // e.g. "4.2f", "0.0f", "-4.2f"
    if (s.length() > 1 && s[s.length() - 1] == 'f')
    {
        std::string noSuffix = s.substr(0, s.length() - 1);
        if (noSuffix.find('.') != std::string::npos)
            return FLOAT_LIT;
    }

    // double literal: contains a decimal point (no 'f' suffix)
    if (s.find('.') != std::string::npos)
        return DOUBLE_LIT;

    // everything else is treated as an integer
    return INT_LIT;
}

// printFloat: print the float value with at least one decimal place.
// NaN and infinity are printed as their respective pseudo-literals.
static void printFloat(float f)
{
    if (std::isinf(f))
        std::cout << (f > 0.0f ? "+inff" : "-inff");
    else if (std::isnan(f))
        std::cout << "nanf";
    else if (fmod(static_cast<double>(f), 1.0) == 0.0)
        // whole number: force ".0" so it looks like a float literal
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    else
        std::cout << f << "f";
}

// printDouble: same idea for double values
static void printDouble(double d)
{
    if (std::isinf(d))
        std::cout << (d > 0.0 ? "+inf" : "-inf");
    else if (std::isnan(d))
        std::cout << "nan";
    else if (fmod(d, 1.0) == 0.0)
        std::cout << std::fixed << std::setprecision(1) << d;
    else
        std::cout << d;
}

void ScalarConverter::convert(const std::string &input)
{
    LiteralType type = detectType(input);
    double      d    = 0.0;  // we store everything as double internally

    // --- Step 1: parse the string into a double ---
    if (type == PSEUDO_LIT)
    {
        if (input == "nan" || input == "nanf")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (input == "+inf" || input == "+inff")
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
    }
    else if (type == CHAR_LIT)
    {
        // extract the character from between the quotes
        d = static_cast<double>(input[1]);
    }
    else
    {
        // strtod parses int, float, double strings correctly
        char *endPtr;
        d = strtod(input.c_str(), &endPtr);
    }

    // --- Step 2: print char ---
    // Use static_cast<char> (value conversion, not reinterpretation)
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 127.0)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(d) << "'";
    std::cout << std::endl;

    // --- Step 3: print int ---
    // static_cast<int> for explicit numeric conversion
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d > static_cast<double>(std::numeric_limits<int>::max()) ||
        d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;

    // --- Step 4: print float ---
    // static_cast<float> narrows the double to float precision
    std::cout << "float: ";
    printFloat(static_cast<float>(d));
    std::cout << std::endl;

    // --- Step 5: print double ---
    std::cout << "double: ";
    printDouble(d);
    std::cout << std::endl;
}
