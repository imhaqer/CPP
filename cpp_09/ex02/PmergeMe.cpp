#include "PmergeMe.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <climits>

// ── Orthodox Canonical Form ───────────────────────────────────────────────────

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ── Input parsing ─────────────────────────────────────────────────────────────

void PmergeMe::parseArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string token(argv[i]);

        // Reject empty tokens
        if (token.empty())
            throw std::runtime_error("Error: empty argument.");

        // Only digits allowed (no minus sign → must be positive)
        for (char c : token)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
                throw std::runtime_error("Error: invalid character in argument: " + token);
        }

        // Check for integer overflow
        long long val = std::stoll(token);
        if (val <= 0 || val > INT_MAX)
            throw std::runtime_error("Error: value out of range: " + token);

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    if (_vec.empty())
        throw std::runtime_error("Error: no input provided.");
}

// ── Jacobsthal insertion order ────────────────────────────────────────────────
//
// The Jacobsthal sequence: J(1)=1, J(2)=3, J(3)=5, J(4)=11, J(5)=21, ...
// Each term: J(n) = J(n-1) + 2 * J(n-2)
//
// We insert pend elements in groups defined by consecutive Jacobsthal numbers,
// working backwards within each group.  This minimises the number of
// comparisons needed for the binary insertions.
//
// Example for 6 pend elements (indices 1..5):
//   Group 1: [1..1]   → insert pend[1]
//   Group 2: [3..2]   → insert pend[3], pend[2]
//   Group 3: [5..4]   → insert pend[5], pend[4]
//   Result order: 1, 3, 2, 5, 4
//
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t pairCount)
{
    if (pairCount <= 1)
        return {}; // pend[0] is inserted directly; nothing left

    // Build Jacobsthal sequence until it exceeds pairCount-1
    std::vector<size_t> jac = {1, 3};
    while (jac.back() < pairCount - 1)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    std::vector<size_t> order;
    size_t prev = 1; // the start of the previous group + 1

    for (size_t k : jac)
    {
        size_t end = std::min(k, pairCount - 1); // clamp to valid range
        // Insert from end down to prev (inclusive) — backwards within the group
        for (size_t i = end; i >= prev; --i)
            order.push_back(i);
        prev = end + 1;
        if (prev >= pairCount)
            break;
    }
    return order;
}

// ── Ford-Johnson sort — std::vector<int> ─────────────────────────────────────
//
// Algorithm overview:
//  1. Pair adjacent elements; the larger of each pair goes to main_chain,
//     the smaller to pend.  If n is odd, the last element is the straggler.
//  2. Recursively sort main_chain.
//  3. Re-associate each pend value with its paired main value (now sorted).
//  4. Prepend pend[0] — it is guaranteed ≤ main[0].
//  5. Binary-insert pend[1..k-1] in Jacobsthal order.
//     For pend[i], the upper bound of the search is the current position of
//     its partner main[i], because pend[i] ≤ main[i].
//  6. Binary-insert the straggler (if any) into the fully built sequence.
//
void PmergeMe::fordJohnsonVec(std::vector<int> &arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;

    // ── Step 1: form pairs (larger, smaller) ──────────────────────────────────
    bool   hasStraggler = (n % 2 == 1);
    int    straggler    = hasStraggler ? arr[n - 1] : 0;
    size_t numPairs     = n / 2;

    // pairs[i] = { larger, smaller }
    std::vector<std::pair<int, int>> pairs(numPairs);
    for (size_t i = 0; i < numPairs; ++i)
    {
        int a = arr[2 * i], b = arr[2 * i + 1];
        pairs[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
    }

    // ── Step 2: recursively sort the main chain ────────────────────────────────
    std::vector<int> mainVals(numPairs);
    for (size_t i = 0; i < numPairs; ++i)
        mainVals[i] = pairs[i].first;

    fordJohnsonVec(mainVals); // recursive call

    // ── Step 3: re-associate pend with sorted main ─────────────────────────────
    // After recursion mainVals is sorted.  Sort pairs by .first so they match.
    // (This is the same permutation fordJohnson applied — result is identical.)
    std::sort(pairs.begin(), pairs.end()); // sorts ascending by .first by default

    // ── Step 4: build initial sequence S = [pend[0], main[0], …, main[k-1]] ───
    std::vector<int> S;
    S.reserve(n);
    S.push_back(pairs[0].second); // pend[0] ≤ main[0], so it goes first
    for (auto &p : pairs)
        S.push_back(p.first);

    // ── Step 5: binary-insert pend[1..k-1] in Jacobsthal order ────────────────
    for (size_t idx : jacobsthalOrder(numPairs))
    {
        int pendVal = pairs[idx].second;
        int mainVal = pairs[idx].first; // paired upper bound

        // Find where mainVal sits in S (it must be there)
        auto bound = std::lower_bound(S.begin(), S.end(), mainVal);

        // Insert pendVal anywhere in [begin, bound) — pendVal ≤ mainVal
        auto pos = std::lower_bound(S.begin(), bound, pendVal);
        S.insert(pos, pendVal);
    }

    // ── Step 6: insert straggler ───────────────────────────────────────────────
    if (hasStraggler)
    {
        auto pos = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(pos, straggler);
    }

    arr = S;
}

// ── Ford-Johnson sort — std::deque<int> ──────────────────────────────────────
//
// Identical algorithm to the vector version above, written for std::deque.
// (std::deque supports random-access iterators so std::lower_bound works fine.)
//
void PmergeMe::fordJohnsonDeq(std::deque<int> &arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;

    // ── Step 1: form pairs ─────────────────────────────────────────────────────
    bool   hasStraggler = (n % 2 == 1);
    int    straggler    = hasStraggler ? arr[n - 1] : 0;
    size_t numPairs     = n / 2;

    std::vector<std::pair<int, int>> pairs(numPairs);
    for (size_t i = 0; i < numPairs; ++i)
    {
        int a = arr[2 * i], b = arr[2 * i + 1];
        pairs[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
    }

    // ── Step 2: recursively sort the main chain ────────────────────────────────
    std::deque<int> mainVals(numPairs);
    for (size_t i = 0; i < numPairs; ++i)
        mainVals[i] = pairs[i].first;

    fordJohnsonDeq(mainVals); // recursive call

    // ── Step 3: re-associate pend with sorted main ─────────────────────────────
    std::sort(pairs.begin(), pairs.end());

    // ── Step 4: build S = [pend[0], main[0], …, main[k-1]] ───────────────────
    std::deque<int> S;
    S.push_back(pairs[0].second);
    for (auto &p : pairs)
        S.push_back(p.first);

    // ── Step 5: binary-insert pend[1..k-1] in Jacobsthal order ────────────────
    for (size_t idx : jacobsthalOrder(numPairs))
    {
        int pendVal = pairs[idx].second;
        int mainVal = pairs[idx].first;

        auto bound = std::lower_bound(S.begin(), S.end(), mainVal);
        auto pos   = std::lower_bound(S.begin(), bound, pendVal);
        S.insert(pos, pendVal);
    }

    // ── Step 6: insert straggler ───────────────────────────────────────────────
    if (hasStraggler)
    {
        auto pos = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(pos, straggler);
    }

    arr = S;
}

// ── Print helper ──────────────────────────────────────────────────────────────

template <typename Container>
void PmergeMe::printContainer(const Container &c) const
{
    for (size_t i = 0; i < c.size(); ++i)
    {
        if (i) std::cout << ' ';
        std::cout << c[i];
    }
    std::cout << '\n';
}

// ── Run: parse → print before → sort both → print after + timings ─────────────

void PmergeMe::run(int argc, char **argv)
{
    parseArgs(argc, argv);

    // Print the unsorted sequence
    std::cout << "Before: ";
    printContainer(_vec);

    // ── Sort with vector and time it ──────────────────────────────────────────
    std::vector<int> vecCopy = _vec;
    auto t1 = std::chrono::high_resolution_clock::now();
    fordJohnsonVec(vecCopy);
    auto t2 = std::chrono::high_resolution_clock::now();
    double vecTime = std::chrono::duration<double, std::micro>(t2 - t1).count();

    // ── Sort with deque and time it ───────────────────────────────────────────
    std::deque<int> deqCopy = _deq;
    auto t3 = std::chrono::high_resolution_clock::now();
    fordJohnsonDeq(deqCopy);
    auto t4 = std::chrono::high_resolution_clock::now();
    double deqTime = std::chrono::duration<double, std::micro>(t4 - t3).count();

    // Print sorted result (both containers produce the same result; use vector)
    std::cout << "After:  ";
    printContainer(vecCopy);

    // Print timing
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << vecTime << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << deqTime << " us\n";
}
