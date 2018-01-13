# Kata 0: Two Sum

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target. You may assume that each input would have ***exactly*** one solution, and you may not use the same element twice.

**Example:**
```
Given nums = [2, 7, 11, 15], target = 9,    
Because nums[0] + nums[1] = 2 + 7 = 9,  return [0, 1].
```

### Context
* The input only contains positive integers
* The output must contain one and only one pair of indices
* The input must always contain at least one solution
* There is no specific oreder in the input
* The numbers in the input array do not repeat

### Cases
#### Base Case
The base case is where the input array has only two numbers. 
##### Solution
```
return [0, 1]
```
#### Arrray lenght > 2
This is the common case where the input array has more than two numbers.
##### Suggested Solution
```
1. Start from the first index and check if the value is lower than the target. If not, then go to the next index.

2. Calculate the complement with the current value and tha target value. Example: If the value is 5 and target is 7; the complement is 2.

3. Use a search algorithm to look for the index of the complement number. If it does not exist, go to step one usign the next index.
```
##### Complexity analysis
* Calculating the complement is constant.                 (1)
* It is needed to go through all elements of the array.   (n)
* Search algorithm (Used every time an index is selected):
  * Linear search   (n)
  * Hash table      (1 + something related to array size)

### Algorithm for the solution
1. Construct a hash table from the input    (n)
1. Select an index with a valid value       (n)
   1. Calculate the complement              (1)
   1. Search for it with the hash table     (1)
1. Return the two indices                   (1)

Complexity is 2n + 3 = *O(n)*

