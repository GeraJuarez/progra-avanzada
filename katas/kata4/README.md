# Kata 4: Valid Number

Validate if a given string is numeric.

Some examples:

`"0"` => `true`

`" 0.1 "` => `true`

`"abc"` => `false`

`"1 a"` => `false`

`"2e10"` => `true`

**Note:** It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

## Context

* String as input
* Boolean as input
* Input mas length is 255
* It can have decimal part, using only `.` to represent it
* To represent exponents, only `e` is valid.
* Valid operations do not count as numbers.
* There can be spaces only before and after the number
* A coma can be used for numbers with more than three digits

## Solution

A simple lexical analyzer can solve this problem. A Deterministic Finite Automaton (DFA) with the correct rules to accept if the input represents a number.

Current state, char | next state
-|-
q0, (blank) | q0
q0, number | q1
q1, `,` | q4
q2, `,` | q4
q3, `,` | q4
q4, number | q5
q5, number | q6
q6, number | q7
q7, `,` | q4
q7, `.` | q9
q7, e | q11
q1, number | q2
q2, number | q3
q3, number | q8
q1, `.` | q9
q2, `.` | q9
q3, `.` | q9
q1, `e` | q9
q2, `e` | q9
q3, `e` | q9
q8, number | q8
q8,  `.`| q9
q8, e | q11
q9, number | q10
q10, number | q10
q10, e | q11
q11, number | q12
q12, number | q12
q11, (blank) | q13
q13, (blank) | q13

### Steps

* Read the input and save it.
* Read the string once comparing char by char using the logic from the DFA from above.
* If the functions is able to reach the end of the string without returning `false`, then the input is a valid function.

## Analysis

The input is only read once, hence the time complexity is `O(n)`.