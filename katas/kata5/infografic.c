#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "infografic.h"

void printFrequencies(char *key, int value) 
{
    printf("%s %d \n", key, value);
}

void countWords()
{
    int character;
	char word[250];
	int j;
	int* value;
	int realValue;
	HashInt hashTable;
	hashInit(&hashTable, 100);

	while ( !feof(stdin) )
	{
		character = fgetc(stdin);

		if (isalnum(character))
		// Get each character and convert it to lower case
		{
			word[j] = (char)tolower(character);
			j++;
		}
		else
		// A blank space or any other symbol is found
		{
			word[j] = '\0';		// Close the string

			if (j > 0)
			{
				// Look for the word in the hash table
				value = hashGet(&hashTable, word);

				if (value == NULL)
				{
					realValue = 1;
				}
				else
				{
					realValue = *value + 1;
				}
				hashInsert(&hashTable, word, realValue);
			}
			j = 0; // Reset the counter for the next word
		}
	}
	forEach(&hashTable, printFrequencies); // Print the frecuency of each word
}