#include "Span.hpp"
#include <algorithm>  // std::sort, std::min_element, std::max_element
#include <stdexcept>

// Constructor: just stores the max capacity; nothing allocated yet
Span::Span(unsigned int n) : _maxSize(n) {}

// Copy constructor
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

// Assignment operator
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor: std::vector handles its own memory
Span::~Span() {}

// addNumber: appends one integer or throws if full
void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw std::length_error("Span: cannot add number, span is full");
    _numbers.push_back(n);
}

// shortestSpan: sort a copy, then check consecutive differences.
// The smallest gap between any two values must be between adjacent
// elements in a sorted array — so sorting + one linear scan is sufficient.
int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Span: need at least 2 numbers to compute a span");

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];  // first gap as starting point
    for (std::size_t i = 2; i < sorted.size(); i++)
    {
        int gap = sorted[i] - sorted[i - 1];
        if (gap < shortest)
            shortest = gap;
    }
    return shortest;
}

// longestSpan: the furthest any two numbers are apart is simply max - min
int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Span: need at least 2 numbers to compute a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}
