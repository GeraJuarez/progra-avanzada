# Practica4

My first C library.

A hash table with a string as the key and the value as any data type.

(void*) will be used to save any type of data.

Key -> char*

Value -> void*

## Structures to implement

* Element:
  * It will contain the main data tu save. The key and the value
* HashElement:
  * It will contain an array of `Elements`, an index to find the data and a `size` value to store the curretn number of `Elements`. This will be used as a `vector`because it will increase the size dynamically.
* Array of hash Element: The basic structure that will contain `HashElements`.

## Functions to implement

* Init:
  * Initialize default values for the structure using the size assigned by the user
* Insert:
  * Using the key as a parameter, it will create another `Element` in the array or add it while dynamically increasing the size of the vector.
* Get:
  * Using a string as parameter, it wiil hash it and find the desired value. 