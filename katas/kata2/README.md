# Kata 2: Strong Password Checker

A password is considered strong if below conditions are all met:

1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function `strongPasswordChecker(s)`, that takes a string `s` as input, and return the MINIMUM change required to make `s` a strong password. If `s` is already strong, return `0`.

## Context

* Insertion, deletion or replace of any one character are all considered as one change.
* Case sensitive for third condition.
* A change can be done to met more than one condition.

## Cases

### *String lenght is in range [6, 20]*

#### Condition 2 and 3 is not met

The number of changes will be the max number of faults between condition 2 and 3. It is needed to replace one character for each repeated character, those can include the an uppercase character, a lowercase character or a digit.

#### Only condition 2 is not met

The number of changes is the number of necessary replaces to add an uppercase character, a lowercase character or a digit.

#### Only condition 3 is not met

The number of changes is the number of necessary replaces to remove a repeated characters.

### *String lenght is less than 6*

If only condition 1 is not met, the number of changes is the number of inserts to add the remaining characters.

#### Condition 2 and 3 is not met

The number of changes is the number of replaces to remove repeated characters and met condition 2, plus the number of insertions to add the remaining characters.

#### Only condition 2 is not met

The number of changes is the number of the max number of insertions needed to met condition 1 or 2. In other words, is needed to insert or replace characters to met condition 2, and if condition 1 is not met, then add the remainin needed characters.

#### Only condition 3 is not met

The number of changes is the number of replaces to remove repeated characters plus the number of insertions to met condition 1.

### *String lenght is greater than 20*

If only condition 1 is not met, the number of changes is the number of deletes to remove the extra characters.

#### Condition 2 and 3 is not met

The number of changes is the number of replaces to met both condition 2 and 3 plus the number of deletes to remove the extra characters. If the number of faults in condition 3 are greater than the faults from condition 2, then, the number of deletes is the max between the faults of condition 3 and the extra characters.

#### Only condition 2 is not met

The number of changes is the number of replaces to met condition 2 and the number of deletes to remove the extra characters.

#### Only condition 3 is not met

The number of changes is the number of deletes of the max between the extra characters and the number of repeated characters.

## Complexity

To get all necessary variables to calculate the number of changes, the string is read only once. Thus, the complexity is `O(n)`.