# Kata 5: Infografic

**You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.**

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴ , where the keys are words and the values are the number of times the words occurred.

**Think about capitalized words.** For example, look at these sentences:

"After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of  2

## Context

* Each word is separated by spaces.
* A capitalized word is the same as a non capitalized one.
* The input is only one string, a large one.
* The data must be stored in a hash table.
* Punctuation symbols must be ignored.

## Solution

The problem is already telling us what to use to solve the problem, with a hash table. To save space, each word that is read must be saved into the hash table; is also needed to keep track of the end of each word and non alphanumeric symbols.

* Read character by character
* If it is an alphanumeric symbol, insert the current word into a hash table
* When the word is new, set the value of the word inside the hash table to 1, otherwise add 1 to the existing value.

## Analysis

The time complexity is only `n`, where `n` is the size of the input.