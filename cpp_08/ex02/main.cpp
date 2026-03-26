#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main() {
    std::cout << "=== MutantStack Basic Test ===\n\n";

    // --- Create MutantStack and push elements ---
    MutantStack<int> mstack;
    std::cout << "Pushing: 5, 17\n";
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << " (expected 17)\n";

    std::cout << "Popping top element...\n";
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << " (expected 1)\n";

    std::cout << "Pushing: 3, 5, 737, 0\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // --- Forward iteration (bottom to top) ---
    std::cout << "\n--- Iterating from bottom to top ---\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // --- Copy to std::stack ---
    std::stack<int> s(mstack);
    std::cout << "\nCopy to std::stack, top element: " << s.top() << " (expected 0)\n";

    // --- Same test with std::list ---
    std::cout << "\n--- Same test with std::list ---\n";
    std::list<int> lst = {5, 3, 5, 737, 0};
    for (std::list<int>::iterator li = lst.begin(); li != lst.end(); ++li)
        std::cout << *li << " ";
    std::cout << std::endl;

    // --- Reverse iteration (top to bottom) ---
    std::cout << "\n--- Reverse iteration (top to bottom) ---\n";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // --- Empty stack edge case ---
    MutantStack<int> emptyStack;
    std::cout << "\n--- Empty stack tests ---\n";
    std::cout << "Empty stack size: " << emptyStack.size() << " (expected 0)\n";
    std::cout << "Empty stack begin == end? "
              << (emptyStack.begin() == emptyStack.end() ? "yes" : "no") << "\n";

    // --- Copy constructor test ---
    MutantStack<int> copyStack(mstack);
    copyStack.push(999);
    std::cout << "\n--- Copy constructor test ---\n";
    std::cout << "Original top: " << mstack.top() << " | Copy top: " << copyStack.top() << "\n";

    // --- MutantStack with std::list as underlying container ---
    std::cout << "\n--- MutantStack with std::list as container ---\n";
    MutantStack<int, std::list<int>> lstStack;
    lstStack.push(11);
    lstStack.push(22);
    lstStack.push(33);

    std::cout << "Elements (bottom to top): ";
    for (auto it = lstStack.begin(); it != lstStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}