# Proyecto 02: Red Tape Committee

You are the head of the Department of Redundancy Reduction and Superfluity Shrinkage. Currently, the department cannot agree on whether there is too much "red tape" (inefficiency) in the department itself. They have asked you to form a Red Tape Committee to vote on the issue.

The department has `N` members. For each member, you know the probability `P`<sub>`i`</sub> that that member will vote "Yes". If a member does not vote "Yes", they necessarily vote "No"; nobody abstains.

You must choose exactly `K` members to be on the committee. The department rules dictate that `K` must be an even number to allow for ties, which are seen as part of a healthy bureaucracy.

If you choose committee members to maximize the probability of a tie, what is that probability?

## Input

The first line of the input gives the number of test cases, `T`. `T` test cases follow; each consists of two lines. The first line of a test case consists of two integers `N` and `K`, the sizes of the department and the committee. The second line of a test case consists of `N` decimal values `P`<sub>`i`</sub>; each has exactly two decimal places of precision and represents the probability that the `i-th` department member will vote "Yes".

## Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is a floating-point number: the maximum possible probability of a tie. `y` will be considered correct if it is within an absolute or relative error of 10<sup>-6</sup> of the correct answer.

## Context

* `T`: Test cases
* `N`: Size of the committee
* `K`: Size of the department
* 1 <= `T` <= 100
* 2 <= `K` <= N
* `K` es even
* 0.00 <= `P`<sub>`i`</sub> <= 1.00
* Small dataset: 2 <= N <= 16
* Large dataset: 2 <= N <= 200

## Breakdown

* Read up to 100 test cases.
* Store each given probability of every department.
* Take the best `K` members that can maximize the probability of a tie.
* Calculate the tie proability given a set of probabilities.

## Solution

For every test case, the process will be the same. After reading `N` and `K`, two new arrays of type `double` (for greater precision) will be initialized. One to store the `N` probabilities and the second to store the `K` probabilities to maximize the probability of a tie.

The given `N` numbers can be stored in an array of size `N` since it will never be greater than 200, in other  words, it has constant size.

Sorting the array of `N` elements can make it easier to choose those that maximize the tie probability. After that, the best is to choose from the minimum and maximum extremes of the array, the smaller and larger probability. One thing to consider is that, if either the maximum or the minimum probability is below or above (respectively) 0.5, then is better to pick the probabilities closer to 0.5. I do not know how to mathematically prove this, but under a range like that, where one limit is around 50%, I think that the best you can do is to have a 50% of a tie when choosing the probabilities closer to 0.5.

---

### Solution 2

After doing some testing, the first solution fails when the average of the probabilities is around 0.5 and the range of the minimum and the maximum probability is really small.

This new solution tries to pick elements of the both extremes of the probability array. It picks the last `K` elements of the array and calculate its probability. Then it picks the last `K – 1` elements and the first one and calculate the tie probability and it keeps the larger one. This keeps going until it picks the first `K` elements.

---

To calculate the tie probability, a matrix that keeps track of the YES and NO possible choices is used. A great explanation of what is theorically doing can be seen [here](https://code.google.com/codejam/contest/10224486/dashboard#s=a&a=1]).

## Analysis

* Sorting the array with bucket sort gives a time complexity of `O(n)`.
* The tie probability calculation is has a loop that goes to K/2 and a nested loop that goes from the outer index to N. The inner loop is getting smaller for every outer loop iteration. This is actually doing K(K+1)/2 operations in total which is no larger than `O(K^2)`
* Total time: `N + K^2`

---

* For the new solution: the sorting does not change.
* There is an outer loop that iterates `K` times.
* To select memebers it iterates `K` times
* The tie probability calculation does not change: `O(K^2)`
* The time complexity is: `N + K^2 + K^3` or  `O(N + K^3)`