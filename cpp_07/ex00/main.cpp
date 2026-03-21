#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    // --- integer tests (from the subject) ---
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    // --- string tests (from the subject) ---
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // --- edge case: equal values ---
    int x = 5;
    int y = 5;
    // when equal, min and max both return the second argument
    std::cout << "min( 5, 5 ) = " << ::min(x, y) << std::endl;
    std::cout << "max( 5, 5 ) = " << ::max(x, y) << std::endl;

    // --- edge case: negative numbers ---
    int neg1 = -10;
    int neg2 = -3;
    std::cout << "min( -10, -3 ) = " << ::min(neg1, neg2) << std::endl;
    std::cout << "max( -10, -3 ) = " << ::max(neg1, neg2) << std::endl;

    return 0;
}
