#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include "Span.hpp"

#define LINE "========================================"

// Helper to print test results
void printResult(const std::string &testName, bool pass, const std::string &msg = "")
{
    std::cout << "[" << (pass ? "PASS" : "FAIL") << "] " << testName;
    if (!msg.empty())
        std::cout << " -> " << msg;
    std::cout << std::endl;
}

int main(void)
{

    // --- Subject's example ---
    std::cout << ">>> SUBJECT EXAMPLE\n";
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected: 2)" << std::endl;
    std::cout << "longestSpan:  " << sp.longestSpan()  << " (expected: 14)" << std::endl;

    // --- Full span exception ---
    std::cout << "\n>>> FULL SPAN EDGE CASE\n";
    try
    {
        sp.addNumber(42);
        printResult("Adding number to full span", false, "no exception thrown");
    }
    catch (const std::exception &e)
    {
        printResult("Adding number to full span", true, e.what());
    }

    // --- 0 or 1 element span ---
    std::cout << "\n>>> TINY SPAN EDGE CASE\n";
    Span tiny(1);
    try
    {
        tiny.shortestSpan();
        printResult("Shortest span with 0 elements", false, "no exception thrown");
    }
    catch (const std::exception &e)
    {
        printResult("Shortest span with 0 elements", true, e.what());
    }

    tiny.addNumber(7);
    try
    {
        tiny.longestSpan();
        printResult("Longest span with 1 element", false, "no exception thrown");
    }
    catch (const std::exception &e)
    {
        printResult("Longest span with 1 element", true, e.what());
    }

    // --- All identical values ---
    std::cout << "\n>>> ALL IDENTICAL VALUES\n";
    Span same(4);
    same.addNumber(5);
    same.addNumber(5);
    same.addNumber(5);
    same.addNumber(5);
    std::cout << "All same -> shortestSpan: " << same.shortestSpan()
              << ", longestSpan: " << same.longestSpan() << std::endl;

    // --- Large test: 10 000 random numbers ---
    std::cout << "\n>>> LARGE SPAN TEST (10,000 numbers)\n";
    const unsigned int BIG = 10000;
    Span big(BIG);

    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> randNums;
    for (unsigned int i = 0; i < BIG; i++)
        randNums.push_back(rand());

    big.addRange(randNums.begin(), randNums.end());
    std::cout << "Large span shortestSpan: " << big.shortestSpan() << std::endl;
    std::cout << "Large span longestSpan:  " << big.longestSpan()  << std::endl;


    return 0;
}