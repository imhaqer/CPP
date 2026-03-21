#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
    // --- vector test: value present ---
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --- vector test: value NOT present ---
    try
    {
        easyfind(vec, 99);
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    // --- list test ---
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --- deque test ---
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(dq, 300);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --- edge case: empty container ---
    std::vector<int> empty;
    try
    {
        easyfind(empty, 1);
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception on empty: " << e.what() << std::endl;
    }

    // --- edge case: first element ---
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found first element: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --- edge case: last element ---
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 40);
        std::cout << "Found last element: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
