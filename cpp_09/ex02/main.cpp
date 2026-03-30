#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: usage: ./PmergeMe <positive integers...>\n";
        return 1;
    }

    PmergeMe pm;
    try
    {
        pm.run(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
