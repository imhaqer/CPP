#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: usage: ./RPN \"<expression>\"\n";
        return 1;
    }

    RPN rpn;
    try
    {
        rpn.evaluate(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
