#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cctype>

enum LiteralType { CHAR_LIT, INT_LIT, FLOAT_LIT, DOUBLE_LIT, PSEUDO_LIT };

static LiteralType detectType(const std::string &s)
{
    // pseudo-literals
    if (s == "nan" || s == "+inf" || s == "-inf" ||
        s == "nanf" || s == "+inff" || s == "-inff")
        return PSEUDO_LIT;

    // quoted char literal: 'x'
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return CHAR_LIT;

    // single non-digit printable char (shell already stripped quotes)
    if (s.length() == 1 && std::isprint(static_cast<unsigned char>(s[0])) && !std::isdigit(s[0]))
        return CHAR_LIT;

    // float literal: ends in 'f' and has a decimal point
    if (s.length() > 1 && s[s.length() - 1] == 'f')
    {
        std::string noSuffix = s.substr(0, s.length() - 1);
        if (noSuffix.find('.') != std::string::npos)
            return FLOAT_LIT;
    }

    // double literal: has a decimal point
    if (s.find('.') != std::string::npos)
        return DOUBLE_LIT;

    return INT_LIT;
}

static void printFloat(float f)
{
    if (std::isinf(f))
        std::cout << (f > 0.0f ? "+inff" : "-inff");
    else if (std::isnan(f))
        std::cout << "nanf";
    else if (fmod(static_cast<double>(f), 1.0) == 0.0)
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    else
        std::cout << f << "f";
}

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
    double      d    = 0.0;

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
        // handle both 'x' (quoted) and x (shell-stripped)
        d = static_cast<double>(input.length() == 3 ? input[1] : input[0]);
    }
    else
    {
        char *endPtr;
        d = strtod(input.c_str(), &endPtr);
    }

    // char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 127.0)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(d) << "'";
    std::cout << std::endl;

    // int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d > static_cast<double>(std::numeric_limits<int>::max()) ||
        d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;

    // float
    std::cout << "float: ";
    printFloat(static_cast<float>(d));
    std::cout << std::endl;

    // double
    std::cout << "double: ";
    printDouble(d);
    std::cout << std::endl;
}