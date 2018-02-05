# Kata 3: Judge Route Circle

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the **original place**.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are `R` (Right), `L`(Left), `U` (Up) and `D` (down). The output should be true or false representing whether the robot makes a circle.

**Example 1:**

>**Input:** "UD"  **Output:** true

**Example 2:**

> **Input:** "LL"  **Output:** false

## Context

* There are only four valid moves.
* The output is true only if the robot is at its original postion when it stops moving.
* If a char is different from the valid moves, the program will stop.

## Solution

1. Initialize two variables that represent the position in `x` and `y`.
2. Read the input char by char.
3. `R` and `L` represent values of `x`, positive and negative respectively; `U` and `D` represent values of `y`, positive and negative respectively.
4. Return `true` if both `x` and `y` are zero after reading all the input.

## Complexity Analysis

The output is only read once. Hence the time complexity is `O(n)`.