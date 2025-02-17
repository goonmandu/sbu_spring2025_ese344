# 1. Correctness of Horner's Method
Given:
```
P(x) =   a_0 * x^0
       + a_1 * x^1
       + a_2 * x^2
         ...
       + a_n * x^n
```
and
```
HORNER(A: coeff array,
       n: last index of array,
       x: base):
       
    p = 0;
    for (i: n...0):
        p = A[i] + x * p;
    
    return p;
```

## a) Running time of `HORNER`
The algorithm has one `for` loop, iterating from `n` to 0.<br>
The only statement within the loop multiplies `p` by `x` and adds a constant `A[n]`, a constant-time operation.<br>
Therefore, it does a constant-time operation `n` times, resulting in a time complexity of O(n).

## b) Pseudocode for naive-evaluation of P(x)
```
NAIVE_POLYNOM(A: coeff array,
              n: how many iters,
              x: base):

    ret = 0;
    for (i: 0...n):
        t = x;
        for (_: 0...i):
            t *= x;  // Raise x to power of i
        ret += A[i] * t;
    
    return ret;
```
The outer loop `for (i: 0...n)` executes `n` iterations of the inner loop.<br>
The inner loop `for (_: 0...i)` executes `i` iterations of a constant operation.<br>
Since `i` = `n`, this has O(n^2) time complexity. Therefore, `NAIVE_POLYNOM` is quadratically worse than `HORNER`.

## c) Loop Invariant Proof of `HORNER`
Given invariant:
- For each iteration of `for` loop in `HORNER`,<br>
  - P(x) = ∑<sub>k=0</sub><sup>n-(i+1)</sup> A<sub>k+i+1</sub>x<sup>k</sup><br>

Show that at termination of `HORNER`, P(x) = ∑<sub>k=0</sub><sup>n</sup> A<sub>k</sub>x<sup>k</sup>.

Proof (by mathematical induction).

1. Initialization: Base Case.
- Before the loop execution, i = n+1, and p = 0. Since no values have been summed yet, P(x) is correctly 0.
- Therefore, p = P(x) = 0. Initialization is complete.

2. Maintenance: Inductive Step.
- Assume that the invariant holds for an arbitrary i. That is,<br>
  <p style="text-align:center">p = ∑<sub>k=0</sub><sup>n-(i+1)</sup> A<sub>k+i+1</sub>x<sup>k</sup></p>
- During the `for` loop, p is updated:<br>
  <p style="text-align:center">p ← A<sub>i</sub> + px</p>
- Substituting the assumption into the previous equation:<br>
  <p style="text-align:center">p ← A<sub>i</sub> + (∑<sub>k=0</sub><sup>n-(i+1)</sup> A<sub>k+i+1</sub>x<sup>k</sup>) * x</p>
- Simplifying:<br>
  <p style="text-align:center">p ← A<sub>i</sub> + (∑<sub>k=0</sub><sup>n-(i+1)</sup> A<sub>k+i+1</sub>x<sup>k+1</sup>)</p>
- Combining A<sub>i</sub> = A<sub>i</sub>x<sup>0</sup> into the summation:
  - Setting m = k + 1:<br>
    <p style="text-align:center">A<sub>i</sub>x<sup>0</sup> + ∑<sub>m=1</sub><sup>n-i</sup> A<sub>m+i</sub>x<sup>m</sup></p>
  - Since the summation expands to A<sub>i+1</sub>x<sup>1</sup> + A<sub>i+2</sub>x<sup>2</sup> + ..., we can prepend A<sub>i</sub>x<sup>0</sup> into the summation to form:<br>
    <p style="text-align:center">∑<sub>m=0</sub><sup>n-i</sup> A<sub>m+i</sub>x<sup>m</sup></p>
    which is the same as the invariant P(x) but with a decremented i, analogous to one iteration of the loop finishing.
- Therefore, the invariant is maintained.

3. Termination.
- The loop exits when the iteration for i = 0 is complete.
- When the loop exits, i therefore can be treated as -1. When i = -1, as per the invariant:
  <p style="text-align:center">P(x) = ∑<sub>k=0</sub><sup>n</sup> A<sub>k</sub>x<sup>k</sup><br></p>
  which was to be shown.