#pragma once

#include <vector>
#include <deque>
#include <string>

// PmergeMe: sorts a sequence of positive integers using the
// Ford-Johnson (merge-insert) sort algorithm.
//
// Two separate implementations are provided:
//   - one using std::vector
//   - one using std::deque
// Both use the same algorithm but are kept separate as required by the subject.
class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // Parse argv tokens into the internal containers and run both sorts.
    // Throws std::runtime_error on invalid input.
    void run(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // Parse and validate command-line arguments
    void parseArgs(int argc, char **argv);

    // Ford-Johnson sort on std::vector<int>
    void fordJohnsonVec(std::vector<int> &arr);

    // Ford-Johnson sort on std::deque<int>
    void fordJohnsonDeq(std::deque<int> &arr);

    // Jacobsthal insertion order for indices [1 .. pairCount-1]
    // Returns the indices in the order they should be binary-inserted
    std::vector<size_t> jacobsthalOrder(size_t pairCount);

    // Print a container on one line
    template <typename Container>
    void printContainer(const Container &c) const;
};
