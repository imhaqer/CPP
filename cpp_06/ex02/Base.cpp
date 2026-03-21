#include "Base.hpp"
#include <iostream>
#include <cstdlib>  // rand

// Virtual destructor must be defined (even if empty) so the vtable exists.
Base::~Base() {}

// generate: pick one of A, B, C randomly.
// rand() % 3 gives 0, 1, or 2 — map each to a class.
// srand() is called once in main, not here.
Base *generate(void)
{
    int r = rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

// identify (pointer version):
// dynamic_cast<T*> returns a valid pointer if the object is of type T,
// or NULL if it isn't. We try each type in order.
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

// identify (reference version):
// dynamic_cast<T&> throws std::bad_cast when the cast fails instead of
// returning NULL (there is no null reference). We catch the exception
// and move on to the next type.
// No pointers are used inside this function.
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "unknown" << std::endl;
}
