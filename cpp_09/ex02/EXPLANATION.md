# PmergeMe — Ford-Johnson (Merge-Insert) Sort: Step-by-Step Explanation

## What is the Ford-Johnson Algorithm?

The **Ford-Johnson algorithm** (also called *merge-insert sort*) is a comparison-based
sorting algorithm designed to minimise the **total number of comparisons** needed to
sort n elements.  It was described by L. R. Ford and S. M. Johnson in 1959 and
referenced in *The Art of Computer Programming, Vol. 3* by Knuth (Merge Insertion,
page 184).

The key idea: rather than sorting naively, we carefully choose the **order** in which
we insert elements so that each binary search covers the smallest possible range.

---

## High-Level Structure

```
Input: [3, 5, 9, 7, 4]

Step 1  →  Pair & compare elements
Step 2  →  Recursively sort the "main chain" (the larger of each pair)
Step 3  →  Re-associate the "pend chain" (the smaller of each pair)
Step 4  →  Build the initial sequence: prepend pend[0]
Step 5  →  Binary-insert remaining pend elements in Jacobsthal order
Step 6  →  Binary-insert the straggler (if odd number of elements)

Output: [3, 4, 5, 7, 9]
```

---

## Detailed Walk-Through

### Input: `[3, 5, 9, 7, 4]`

---

### Step 1 — Pair elements and compare

Take adjacent pairs.  Put the **larger** value in the *main chain* and the
**smaller** value in the *pend chain*.

```
Pair 1: (3, 5)  →  main: 5,  pend: 3
Pair 2: (9, 7)  →  main: 9,  pend: 7
Remaining: 4   →  straggler (odd element, no partner)

main  = [5, 9]
pend  = [3, 7]
strag = 4
```

**Property established:** `pend[i] ≤ main[i]` for every pair.

---

### Step 2 — Recursively sort the main chain

Apply the same algorithm to `[5, 9]`:

```
Pair: (5, 9) → main: 9,  pend: 5
No straggler.

Recursively sort [9] → trivially sorted.

Re-associate: pend[0]=5, main[0]=9
Build S = [pend[0], main[0]] = [5, 9]
No more pend elements to insert.

Sorted main chain: [5, 9]
```

Back at the outer level, `main = [5, 9]` (sorted).

---

### Step 3 — Re-associate pend with sorted main

Now that `main` is sorted, we sort the (main, pend) pairs in the same order:

```
Original pairs:  (5, 3)  (9, 7)
Sorted by main:  (5, 3)  (9, 7)   ← already in order

pairs[0] = (main=5, pend=3)
pairs[1] = (main=9, pend=7)
```

The invariant is preserved: `pend[i] ≤ main[i]`.

---

### Step 4 — Build the initial sequence S

We know `pend[0] ≤ main[0]` so we can **prepend** `pend[0]` safely.

```
S = [pend[0], main[0], main[1]]
S = [3,       5,       9      ]
```

---

### Step 5 — Insert remaining pend elements in Jacobsthal order

#### Why Jacobsthal order?

If we inserted `pend[1], pend[2], pend[3], …` in order, each binary search
would need to cover more and more elements.  The **Jacobsthal sequence**
gives us an insertion order that keeps every binary search range as short
as possible, minimising total comparisons.

#### The Jacobsthal sequence

```
J(1) = 1
J(2) = 3
J(n) = J(n-1) + 2 × J(n-2)

Sequence: 1, 3, 5, 11, 21, 43, 85, 171, …
```

#### How the insertion groups work

We insert pend elements in *groups* defined by consecutive Jacobsthal numbers,
working **backwards** within each group:

```
Group 1 (J=1):  insert pend[1]
Group 2 (J=3):  insert pend[3], pend[2]
Group 3 (J=5):  insert pend[5], pend[4]
Group 4 (J=11): insert pend[11], pend[10], …, pend[6]
…
```

Working backwards within a group means the search range for each element is
already bounded by elements that were inserted **in the same batch**, not
pushed out by earlier insertions.

#### Applying it to our example (only pend[1] remains)

Jacobsthal order for `numPairs = 2`: only index `1`.

```
Insert pend[1] = 7
  Upper bound: main[1] = 9  (we know 7 ≤ 9)
  Binary search in S = [3, 5, 9] up to (but not including) 9
  Search range: [3, 5]  → 7 goes after 5
  S = [3, 5, 7, 9]
```

---

### Step 6 — Insert the straggler

The straggler (4) has no known upper bound, so we binary search the full sequence.

```
S = [3, 5, 7, 9]
Insert 4: binary search → between 3 and 5
S = [3, 4, 5, 7, 9]  ✓
```

---

## Why the Search Range is Bounded

For `pend[i]`, we search only in `[S.begin(), position_of_main[i])`.

This is valid because the pairing in Step 1 guarantees:

```
pend[i] ≤ main[i]
```

So `pend[i]` **cannot** be placed anywhere after `main[i]` in the sorted order.
The bounded search means each binary search covers at most a predictable number
of elements, directly linked to the Jacobsthal sequence.

---

## Jacobsthal Group Sizes and Comparison Counts

| Group | Jacobsthal range | Elements in group | Max binary-search range |
|-------|-----------------|-------------------|------------------------|
| 1     | 1               | 1                 | 3                       |
| 2     | 2–3             | 2                 | 7                       |
| 3     | 4–5             | 2                 | 11 (= 2×5 + 1)          |
| 4     | 6–11            | 6                 | 23                      |
| k     | …               | J(k)−J(k-1)       | 2^k − 1                 |

Within a group of size m, **binary search costs at most ⌈log₂(2^k)⌉ = k
comparisons** per element, for every element in the group.  This is what makes
Ford-Johnson optimal (or near-optimal) in comparison count.

---

## Code Structure Summary

```
PmergeMe::fordJohnsonVec / fordJohnsonDeq
│
├─ Step 1: form pairs, extract straggler
├─ Step 2: recursive call on main values
├─ Step 3: sort pairs by .first (re-associate pend)
├─ Step 4: S = [pend[0]] + [main[0]…main[k-1]]
├─ Step 5: for each idx in jacobsthalOrder(numPairs):
│            bound = lower_bound(S, main[idx])
│            pos   = lower_bound(S.begin(), bound, pend[idx])
│            S.insert(pos, pend[idx])
└─ Step 6: binary insert straggler into full S
```

Two implementations exist (one for `std::vector`, one for `std::deque`) to
demonstrate how the same algorithm performs differently across container types
due to their internal memory layouts:

- **`std::vector`**: contiguous memory → cache-friendly iteration; insert is O(n)
- **`std::deque`**: segmented memory → slightly higher overhead per element
- For large inputs the deque version is typically a few percent slower.

---

## Example with More Elements: `[3, 5, 9, 7, 4, 2, 6, 1]`

```
n=8, no straggler

Pairs:  (5,3)  (9,7)  (4,2) → wait, compare: arr[4]=4 arr[5]=2 → (4,2)
        (6,1)

Actually: pair indices (0,1)(2,3)(4,5)(6,7)
  (3,5)→(5,3)  (9,7)→(9,7)  (4,2)→(4,2)  (6,1)→(6,1)

main = [5, 9, 4, 6]
pend = [3, 7, 2, 1]

Recursively sort main [5, 9, 4, 6]:
  Pairs: (5,9)→(9,5)  (4,6)→(6,4)
  main2 = [9, 6],  pend2 = [5, 4]
  Recursively sort [9, 6]:
    Pair: (9,6)→(9,6), main3=[9], pend3=[6]
    Sort [9]: trivial
    S = [6, 9]
  main2 = [6, 9] (sorted)
  Re-associate: pairs2 = (6,4), (9,5)
  S = [4, 6, 9]
  Insert pend2[1]=5, bound=9: search [4,6], 5 goes after 4
  S = [4, 5, 6, 9]

Back at outer: main = [4, 5, 6, 9]
Re-associate pairs: (4,2),(5,3),(6,1),(9,7)
S = [2, 4, 5, 6, 9]

Jacobsthal order for numPairs=4: [1, 3, 2]
  Insert pend[1]=3, bound=5: search [2,4], 3 goes after 2 → S=[2,3,4,5,6,9]
  Insert pend[3]=7, bound=9: search [2,3,4,5,6], 7 after 6 → S=[2,3,4,5,6,7,9]
  Insert pend[2]=1, bound=6: search [2,3,4,5], 1 before 2 → S=[1,2,3,4,5,6,7,9]

Final: [1, 2, 3, 4, 5, 6, 7, 9] ✓
```

---

## Key Takeaways

1. **Pair & compare** reduces the problem to sorting half as many elements.
2. **Recursive application** gives the algorithm its merge-sort-like depth.
3. **Jacobsthal insertion order** is the core optimisation — it minimises the
   worst-case number of comparisons compared to sequential insertion.
4. **Bounded binary search** (using the paired main value as upper bound) makes
   each insertion efficient.
5. The algorithm handles **odd-length inputs** naturally via the straggler, which
   is inserted last with no bounded upper limit.
