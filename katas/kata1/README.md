# Kata 1: Find Anagram Mappings

Given two lists `A` and `B`, and `B` is an anagram of `A`. `B` is an anagram of `A` means `B` is made by randomizing the order of the elements in `A`. We want to find an *index mapping* `P`, from `A` to `B`. `A` mapping `P[i] = j` means the `i`th element in `A` appears in `B` at index `j`. These lists `A` and `B` may contain duplicates. If there are multiple answers, output any of them.
For example, given:

```js
A = [12, 28, 46, 32, 50] B = [50, 12, 32, 46, 28]
```

We should return

```js
[1, 4, 3, 2, 0]
```

as  `P[0] = 1` because the `0`th element of `A` appears at  `B[1]`, and `P[1] = 4` because the `1`st element of `A` appears at `B[4]`, and so on.

## Context

* There is always a solution
* There may be more than one answer
* It only outputs one answer
* `A` and `B` have lengths of range `[1, 100]`
* `A[i], B[i]` are integers in range `[0, 10^5]`
* `A` and `B` have equal length

## Cases

### *Base case:* lenght of `A` and `B` is 1

* Return `P = [0]`

### *General case:* lenght of `A` and `B` is greater than 1

* Read `A[i]`, where `i` are from range `[0, lenght of A]`
* Search `A[i]` in `B`
* Return the index of `B` where `A[i]` was found, and save it in `P[i]`
* Let `F` be an array of booleans that keeps tracks of the index of `B` that were used. This solve the case where the integers from `A` or `B` are repeated

## Complexity

* It is needed to iterate over either `A` or `B` at least once `(n)`.
* Search an element in `B` takes `(n)` if a linear search algorithm is used. If a hash table or dictionary is implemented, then it will take `(1 plus something)`.
* The search is used for every element of `A`.
* Changing the value of `F[i]` takes `(1)`.

If a hash table is used, the complexity of the solution is `O(n)`. Otherwise, is `O(n^2)`.
