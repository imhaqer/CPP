#include <iostream>
#include <cstdlib>  // srand
#include <ctime>    // time
#include "Base.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    // Run several rounds so we see all three types eventually
    for (int round = 0; round < 6; round++)
    {
        Base *obj = generate();

        std::cout << "Round " << round + 1 << ": ";
        std::cout << "via pointer: ";
        identify(obj);

        std::cout << "Round " << round + 1 << ": ";
        std::cout << "via reference: ";
        identify(*obj);

        delete obj;
    }

    // --- edge case: fixed types to confirm correctness ---
    std::cout << "\nFixed tests:" << std::endl;

    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "A ptr: "; identify(a);
    std::cout << "B ptr: "; identify(b);
    std::cout << "C ptr: "; identify(c);

    std::cout << "A ref: "; identify(*a);
    std::cout << "B ref: "; identify(*b);
    std::cout << "C ref: "; identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}
