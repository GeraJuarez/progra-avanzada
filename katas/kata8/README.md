# Kata 7: Inflight Entertainment System

You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. **So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length**.

Write a function that takes an integer `flight_length` (in minutes) and a list of integers `movie_lengths` (in minutes) and returns a boolean indicating whether there are two numbers in `movie_lengths` whose sum equals `flight_length`.

## Context

* Assume your users will watch exactly two movies
* Don't make your users watch the same movie twice
* Optimize for runtime over memory

## Solution

* Iterate over all the movie lenghts.
* For every `i` lenght, calculate `flight_length - current length` and look for it in a Hash table.
* Add the current lenght in the hash table.

## Analysis

The `movie_lengths` is iterated only once and the search and add of a Hash table is constant. Hence, time complexity is `O(n)` where `n` is the lenght of `movie_lengths`.