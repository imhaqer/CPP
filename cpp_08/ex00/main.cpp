#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define LINE "========================================"

// Helper to print test result
void printResult(const std::string &testName, bool pass, const std::string &msg = "")
{
    std::cout << "[" << (pass ? "PASS" : "FAIL") << "] "
              << testName;

    if (!msg.empty())
        std::cout << " -> " << msg;

    std::cout << std::endl;
}

int main(void)
{

    // ---------- VECTOR ----------
    std::cout << ">>> VECTOR TESTS\n";

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        int val = *easyfind(vec, 20);
        printResult("Vector: find existing (20)", true, "found " + std::to_string(val));
    } catch (const std::exception &e) {
        printResult("Vector: find existing (20)", false, e.what());
    }

    try {
        easyfind(vec, 99);
        printResult("Vector: find missing (99)", false, "no exception thrown");
    } catch (const std::exception &e) {
        printResult("Vector: find missing (99)", true, e.what());
    }

    std::cout << "\n";

    // ---------- LIST ----------
    std::cout << ">>> LIST TESTS\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try {
        int val = *easyfind(lst, 15);
        printResult("List: find existing (15)", true, "found " + std::to_string(val));
    } catch (const std::exception &e) {
        printResult("List: find existing (15)", false, e.what());
    }

    std::cout << "\n";

    // ---------- DEQUE ----------
    std::cout << ">>> DEQUE TESTS\n";

    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);

    try {
        int val = *easyfind(dq, 300);
        printResult("Deque: find existing (300)", true, "found " + std::to_string(val));
    } catch (const std::exception &e) {
        printResult("Deque: find existing (300)", false, e.what());
    }

    std::cout << "\n";

    // ---------- EDGE CASES ----------
    std::cout << ">>> EDGE CASES\n";

    std::vector<int> empty;

    try {
        easyfind(empty, 1);
        printResult("Empty container", false, "no exception thrown");
    } catch (const std::exception &e) {
        printResult("Empty container", true, e.what());
    }

    try {
        int val = *easyfind(vec, 10);
        printResult("First element", true, "found " + std::to_string(val));
    } catch (const std::exception &e) {
        printResult("First element", false, e.what());
    }

    try {
        int val = *easyfind(vec, 40);
        printResult("Last element", true, "found " + std::to_string(val));
    } catch (const std::exception &e) {
        printResult("Last element", false, e.what());
    }


    return 0;
}