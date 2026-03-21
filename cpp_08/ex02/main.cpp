#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main(void)
{
    // --- subject's example ---
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;   // 17

    mstack.pop();
    std::cout << mstack.size() << std::endl;  // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // iterate from bottom to top using forward iterators
    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // verify MutantStack can be implicitly used as a std::stack
    std::stack<int> s(mstack);
    std::cout << "std::stack copy top: " << s.top() << std::endl;

    // --- same test with std::list to verify same output ---
    std::cout << "\n--- Same test with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    for (std::list<int>::iterator li = lst.begin(); li != lst.end(); ++li)
        std::cout << *li << std::endl;

    // --- additional tests ---

    // reverse iteration
    std::cout << "\nReverse (top to bottom):" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    while (rit != mstack.rend())
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // empty stack edge case
    MutantStack<int> emptyStack;
    std::cout << "\nEmpty stack size: " << emptyStack.size() << std::endl;
    std::cout << "Empty stack begin==end: "
              << (emptyStack.begin() == emptyStack.end() ? "yes" : "no") << std::endl;

    // copy constructor
    MutantStack<int> copy(mstack);
    copy.push(999);
    std::cout << "\nOriginal top: " << mstack.top()
              << " | Copy top: "   << copy.top() << std::endl;

    // MutantStack with a different container (std::list as backing store)
    MutantStack<int, std::list<int> > lstStack;
    lstStack.push(11);
    lstStack.push(22);
    lstStack.push(33);
    for (MutantStack<int, std::list<int> >::iterator i = lstStack.begin();
         i != lstStack.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
