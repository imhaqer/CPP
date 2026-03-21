#ifndef BASE_HPP
#define BASE_HPP

// Base: has only a public virtual destructor.
// The virtual destructor is what enables dynamic_cast to work —
// it makes Base a polymorphic type (has a vtable), which RTTI needs.
// Note: no Orthodox Canonical Form required for this exercise.
class Base
{
public:
    virtual ~Base();
};

// Three concrete classes that inherit from Base.
// They are empty — all we care about is their type identity.
class A : public Base {};
class B : public Base {};
class C : public Base {};

// generate: randomly allocates an A, B, or C and returns it as Base*.
Base *generate(void);

// identify (pointer): prints "A", "B", or "C" depending on the real type.
// Uses dynamic_cast<T*> which returns NULL if the cast fails.
void identify(Base *p);

// identify (reference): same, but takes a reference.
// Uses dynamic_cast<T&> which throws std::bad_cast on failure.
// Pointers are forbidden inside this overload.
void identify(Base &p);

#endif
