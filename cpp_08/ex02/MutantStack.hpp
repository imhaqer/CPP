#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// MutantStack: a std::stack that also supports iteration.
//
// std::stack is an adaptor that wraps another container (std::deque by default).
// It intentionally hides that container to enforce LIFO access only.
// But the underlying container is accessible via the protected member `c`.
//
// By inheriting from std::stack<T> we get all its member functions for free,
// then we expose the underlying container's iterators so clients can loop over it.
//
// The second template parameter (Container) lets callers pick any sequence
// container as the backing store, matching std::stack's own signature.
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    // Bring in iterator types from the underlying container
    typedef typename Container::iterator               iterator;
    typedef typename Container::const_iterator         const_iterator;
    typedef typename Container::reverse_iterator       reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Default constructor
    MutantStack() {}

    // Copy constructor
    MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

    // Assignment operator
    MutantStack &operator=(const MutantStack &other)
    {
        std::stack<T, Container>::operator=(other);
        return *this;
    }

    // Destructor
    ~MutantStack() {}

    // Forward iterators: walk the stack from bottom to top
    // `this->c` is the protected member of std::stack — the real container
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }

    // Reverse iterators: walk from top to bottom
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend()   { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend()   const { return this->c.rend(); }
};

#endif
