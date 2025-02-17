# Inversions
## a) List inversions in `{2, 3, 8, 6, 1}`
(2, 1), (3, 1), (8, 6), (8, 1), (6, 1)

## b) Array with most inversions whose elements are `set({x | int x; 0<x≤n})`
`{n, n-1, n-2 ... 2, 1}` with<br>
<p style="text-align:center">∑<sub>k=1</sub><sup>n</sup> k = n(n + 1) / 2</p>
inversions.

## c) Insertion Sort Runtime vs Inversions
The two are directly proportional as insertion sort must swap every inversion.

## d) Count inversions in O(n log n) time
Refer to `helper_inversions` in `main.cpp`.

This algorithm modifies mergesort in a way that the inversions are counted while merging.

Since the two split vectors are already sorted from least to greatest, if an element in `v1` is chosen to be put into
the result vector, all remaining elements in `v1` are guaranteed to be greater than the element from `v2`,
which satisfies the inversion condition. Therefore, we can simply  count how many elements remain in `v1`
(including the item just compared) and add this number to the total number of inversions seen.
This counting operation is done via `std::distance` which gives the number of elements between two iterators.

When each recursive call returns, the elements counted towards the number of inversions are sorted in one vector
which prevents duplicate counting of inverted element pairs.

The total number of inversions in the array is returned when the entire recursive call chain is complete.