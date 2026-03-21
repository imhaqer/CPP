#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

// Span: stores up to N integers and can compute the shortest/longest span.
// "Span" here means the absolute difference between two numbers in the set.
class Span
{
private:
    unsigned int      _maxSize;   // hard cap on how many numbers can be stored
    std::vector<int>  _numbers;   // the actual stored integers

public:
    // Constructor: sets the maximum capacity
    Span(unsigned int n);

    // Orthodox Canonical Form
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // addNumber: inserts one integer; throws if already at capacity
    void addNumber(int n);

    // addRange: inserts all integers from [begin, end) in a single call.
    // Throws if adding the range would exceed capacity.
    // Using a template so it works with any iterator type.
    template<typename Iter>
    void addRange(Iter begin, Iter end)
    {
        // count how many elements we're about to add
        // (we can't assume random-access iterators, so we compute distance manually)
        unsigned int count = 0;
        for (Iter it = begin; it != end; ++it)
            count++;

        if (_numbers.size() + count > _maxSize)
            throw std::length_error("Span: addRange would exceed max capacity");

        // insert elements one by one
        for (Iter it = begin; it != end; ++it)
            _numbers.push_back(*it);
    }

    // shortestSpan: minimum absolute difference between any two stored numbers.
    // Throws if fewer than 2 numbers are stored.
    int shortestSpan() const;

    // longestSpan: maximum absolute difference (i.e., max - min).
    // Throws if fewer than 2 numbers are stored.
    int longestSpan() const;
};

#endif
