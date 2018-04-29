# Proyecto 03: Forbidden Sum

Mike likes to invent new functions. The latest one he has invented is called *ForbiddenSum*. Let's consider how it can be calculated:

You are given a set `S` of positive integers. The integers are not necessary distinct. *ForbiddenSum* of `S` equals to the minimal **non-negative** integer, that can't be returned by the algorithm described below:

* Choose a random subset `S'` of `S`(it can be empty as well);
* Calculate the sum of all the numbers of `S'` and assign it to the variable `T`;
* Return the value of the variable `T`

I.e. if `S = {1, 1, 3, 7}`, the algorithm can return 0(`S' = {}`), 1(`S' = {1}`), 2(`S' = {1, 1}`), 3(`S' = {3}`), 4(`S' = {1, 3}`), 5(`S' = {1, 1, 3}`), but it can't return 6. So, ForbiddenSum of `S` equals to 6.

Inventing of new function is not the only Mike's hobby. Also, he likes to collect rare and unusual arrays. He is going to share with you one of them.

Formally, Mike gives you one array `A`, consisting of `N` positive integers. After that, he asks you `M` questions, two integers `Li` and `Ri` describe `i`'th question: What does *ForbiddenSum* of `S={ALi, ALi+1, ..., ARi-1, ARi}` equal to?

## Input

The first line contains the only integer `N`. The second line contains `N` integers - the array `A`. `A` is 1-indexed.

The third line contains the only integer `M`. The following `M` lines contain two integer numbers 1 ≤ `Li` ≤ `Ri` ≤ `N` each.

## Output

Output should consists of `M` lines. The `i`'th line should contains the answer to the `i`'th question.

## Context

* 1 ≤ `N`, `M` ≤ 100,000
* 1 ≤ `Ai` ≤ 10^9
* 1 ≤ `A1` + `A2` + ... + `AN` ≤ 10^9

## Breakdown

* Find the forbidden number of any set of numbers.
* Create a subset with the specified range of `L` and `R`.

## Solution

### Solution 1

Using memcpy is enough to copy part of an array into another one within a rnage. Then, to calculate the *forbidden sum* we must first sort the array in non-decreasing order. The lowest non negative number is 0, so in the base case in which a set is empty the forbidden sum equals 1.

To find this sum, it is needed to keep summing the minimum values until the next element is greater than the current sum plus one. This works because the sum of the minimum numbers keeps track of the lower limit of the forbidden sum we want to find; and, once we find a number greater than the current sum plus one, the upper bound is found, hence, the forbidden sum is also found. This is true because this number as the upper bound is greater than the forbidden sum and with the current sum we had of minimum numbers ensures that it cannot create the forbidden sum.

### Solution 2

It uses the same idea of solution 1, but this time, the original array is sorted while storing its original index of the original array. Then, for each `L` and `R`, calculate the forbidden sum using the array of indices and the sorted array `A`. To do this, iterate over the index array and every time an index is found within the range of `L` and `R`, get the number of the current index and use it to calculate the forbidden sum (same as for solution 1).

## Analysis

### Analysis sol 1

There is a loop for `M` to start solving the 'questions'; for every `M`, a subset of `A` is created, sorted and then the forbidden sum is calculated. Worst case scenario, the subset is `N`, this means a complexity of `N lg N` when sorting, `N` to find the forbidden sum and when generating the subset. We have a total time complexity inside the `M` loop of `2N + N lg N`; which means `O(N + MN lg N)`.

### Analysis sol 2

Sorting is `N log N` and for every `M`, the array `A` is iterated once to get the forbidden sum. Total time complexity is `O(N lgN + MN)`.