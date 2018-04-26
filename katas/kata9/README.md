# Kata 9: UTF-8 Validation

A character in UTF8 can be from **1 to 4 bytes** long, subjected to the following rules:

* For 1-byte character, the first bit is a 0, followed by its unicode code.
* For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

Char. number range (hexadecimal) | UTF-8 octet sequence (binary)
-|-
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

**Note:**
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

**Example 1:**

```
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
```

**Example 2:**

```
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

## Context

* The data may represent any numbers of characters.
* More than 4 bytes given as input is not necessary invalid.

## Solution

* Iterate of the the `data` array starting from 0.
* Get the first value and do a right shift three times to get the first five bits.
  * if is less than 15, then there is a 0 at the first bit: 0XXXX
  * if is less than 23, then is an invalid byte: 10XXX
  * if is less than 27, then is stands for a 2 byte UTF-8 character: 110XX
  * if is less than 29, then is stands for a 3 byte UTF-8 character: 1110X
  * if is less than 29, then is stands for a 4 byte UTF-8 character: 11110
* For an n-byte character, take the next `n - 1` following data in the array and do a right shift six timesto get the first two bits.
  * if all of them equals 2 (10 in binary), then is a valid UTF-8 character.

## Analysis

Time complexity is `O(n)` since the array is iterated only once.