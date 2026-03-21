#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "Span.hpp"

int main(void)
{
    // --- subject's example ---
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;  // expected: 2
    std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;  // expected: 14

    // --- edge case: adding to a full span throws ---
    try
    {
        sp.addNumber(42);
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected full-span exception: " << e.what() << std::endl;
    }

    // --- edge case: span with 0 or 1 element throws on span queries ---
    Span tiny(1);
    try
    {
        tiny.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected 1-element exception: " << e.what() << std::endl;
    }

    tiny.addNumber(7);
    try
    {
        tiny.longestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected 1-element exception: " << e.what() << std::endl;
    }

    // --- edge case: all identical values -> shortestSpan == 0, longestSpan == 0 ---
    Span same(4);
    same.addNumber(5);
    same.addNumber(5);
    same.addNumber(5);
    same.addNumber(5);
    std::cout << "All same -> shortest: " << same.shortestSpan()
              << ", longest: " << same.longestSpan() << std::endl;

    // --- large test: 10 000 random numbers using addRange ---
    const unsigned int BIG = 10000;
    Span big(BIG);

    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> randNums;
    for (unsigned int i = 0; i < BIG; i++)
        randNums.push_back(rand());

    big.addRange(randNums.begin(), randNums.end());
    std::cout << "Large span (" << BIG << " numbers):" << std::endl;
    std::cout << "  shortestSpan: " << big.shortestSpan() << std::endl;
    std::cout << "  longestSpan:  " << big.longestSpan()  << std::endl;

    // --- edge case: addRange exceeds capacity ---
    Span small2(3);
    small2.addNumber(1);
    try
    {
        small2.addRange(randNums.begin(), randNums.begin() + 5);
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected overflow exception: " << e.what() << std::endl;
    }

    return 0;
}
