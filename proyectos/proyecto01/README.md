# Robot in the Field

* Time limit: 2.0 second
* Memory limit: 64 MB

There is a field `[−N..N]×[−N..N]`. At initial moment, robot stands at point `(0, 0)`. It starts moving in `(1, 0)` direction. Robot moves according to a program. Program is a correct boolean expression. It contains operators `NOT`, `AND`, `OR` (`NOT` has highest priority, `OR` - lowest), brackets `'('`, `')'`, constants `'TRUE'` and `'FALSE'`, and registers `'A', ..., 'Z'`. Initially, all robot's registers are `FALSE`. Robot moves forward until it reaches a fork. Then, robot evaluate the expression and turns right if it is `TRUE` and turns left if it is `FALSE`. Besides, there are some points in the field, standing on which makes one of robot's registers to invert. You are asked to print robot's route until it falls out of the field.

## Input

First line contains boolean expression. The length of expression `≤ 250`. Second line contains three integers `1 ≤ N ≤ 100`, `0 ≤ M ≤ 100`, `0 ≤ K ≤ 100`. `M` — number of forks, `K` — number of register inverting points. Then follows `M` lines, each of them contains two integers `X`, `Y` — coordinates of forks. Then follows `K` lines, each of them contains two integers `X`, `Y` and character `C` — coordinates of register inverting point and name of register, which inverts. You may assume, that there is no fork at point `(0, 0)`. You may assume, that no two objects (forks or register inverting points) coincide. You may assume, that after some moves robot falls out of the field.

## Output

You should print robot's route to output, every pair of coordinates in separate line.

| input | output|
|---|---|
|NOT((A OR NOT B) AND (A OR B)) OR NOT (A AND NOT B OR TRUE)| 0 0|
|1 5 2| 1 0|
|1 0| 1 -1|
|1 1| 0 -1|
|1 -1| -1 -1|
|-1 -1| -1 0|
|-1 1| -1 1|
|0 1 A| 0 1|
|-1 0 D| 1 1|

## Context

* `N:` Field size.
* `M:` Number fo forks.
* `K:` Number of register inverting points.
* `1 <= N <= 100`
* `0 <= M <= 100`
* `0 <= K <= 100`
* Forks and register inverting points never coincide.
* The robot always falls out of the field after some moves (The program never loops forever).

* Boolean expression length is `<= 250`.
* The robot starts at `(0, 0)`.
* The robots starts facing East.
* The robot always moves forward relative to its position.
* The boolean expression given as an input is always a correct boolean expression.
* The registers of the robot starts as with `FALSE` and it has at most 25 (`A to Z`).
* At a fork, the robot either turns to the right or left whether the boolean expression evaluates `TRUE` or `FALSE` respectively.
* At a register inverting points a specific robot's register value is inverted.

## Breakdown

* Recognize each operation of the boolean expression.
* Parse the boolean expression every time the robot encounter a fork. The parser needs to be coded from scratch to satisfy this problem.
* `scanf()` can be used to read the next lines of the input with this format: `("%d %d %d", var1, var2, var3)`.
* A struct can be used to manipulate the robot and know its current information, this should contain an array of its registers, the position in `x` and `y`, and where its facing.

## Solution

1. Read the boolean expression char by char.
2. Identify key words (`NOT`, `AND`, `OR`, etc.).
3. Generate a simple boolean expression with operators of one character with this relation:
   * `NOT`: `-`
   * `AND`: `*`
   * `OR`: `+`
   * `TRUE`: `1`
   * `FALSE`: `0`
4. Read `N`, `M` and `K`.
5. Initialize a struct for the robot with its default values and an array of booleans that represents the registers:
    * The size of the array of register is 26 (`A...Z`).
    * Normalize the asci value substracting 65 to the characters (`'A' - 65 = 0`).
    * `A` represent index `0` of the array, `Z` represent index `24`.
    * The robot can only face North (`N`), East (`E`), South (`S`) or West (`W`).

### Solution (1)

6. Read `M` forks and store the positions in two arrays. Array `Mx` to store the position in the `X` axis and array `My` to store the position in the `Y` axis for the fork `i`.
7. Read `K` register inverting points and use three arrays to store them. Array `Kx` to store the position in the `X` axis, `Ky` for the `Y` axis and `Kc` to store the register to invert.
8. In a loop while the robot is on the field:
    * Print its position.
    * Look for a fork in the array that matches the current position.
        * Change direction if a fork is found using the boolean expression.
        * *Example:* if facing `N` and the expression returns `TRUE`: then it will face `E`.
    * Look for a register inverting point that matches the current position.
        * Change the register if one is found.
    * Make the robot to move forward.

### Solution (2)

6. Create a 2D array of `2N x 2N` that represents the field.
7. Read `M` forks and store a flag in the position of the field.
8. Read `K` register inverting points and store the register to invert in the field.
9. Do step `8` from [Solution (1)](#solution-1).

### Solution (3)

Same as [Solution (1)](#solution-1) but using a binary search.

* Sort both `Mx` and `Kx` in non-decreasing order having `My`, `Ky` and `Kc` ordered as well with respect to `Mx` and `Kx`.

## Analysis

Reading the boolean expression is constant since the size cannnot be larger than 250. Reading the forks is `M` and the register inverting points is `K`. The number of iterations of the first loop is `C` which is extremely variable because depends a lot of the input. Since the size of the boolean expression is constant, we can say that the parser is constant as well.

* Using [Solution (1)](#solution-1) the first loop has a time complexity of `O((M+K)C)`.
* Using [Solution (2)](#solution-2) the first loop has a time complexity of `O(C)`.
* Using [Solution (3)](#solution-3) the first loop has a time complexity of `O(C(log MK))`.

Solution 1 is the easiest to implement but is the slowest. Solution 2 is easier than solution 3 and faster, but it waste a lot of memory, in the worst case scenario where `N = 100` the 2D array will have a size of 4 x 200 x 200 bytes (160,000 bytes) that is equal to 0.16 mega bytes; it's still inside the memory limit so it is a valid aproach. On the other hand, solution 3 is a better version of solution 1 but is harder to implement.