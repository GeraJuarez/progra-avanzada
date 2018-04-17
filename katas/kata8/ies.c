#include <stdlib.h>
#include <stdio.h>
#include "ies.h"
#include "hash.h"

int iesMoviesForFlight(int flight_length, int* movie_lengths, int movies)
{
    int movieLengthComplement;
    int currentMovie;
    int* foundValue;
    HashInt hashTable;
    hashInit(&hashTable, (2 * flight_length) + 1);

    for (int i = 0; i < movies; i++)
    {
        currentMovie = movie_lengths[i];
        movieLengthComplement = flight_length - currentMovie;
        foundValue = hashGet(&hashTable, movieLengthComplement);
        if (foundValue != NULL) 
        {
            printf("Current len: %d\n", currentMovie);
            printf("Found len: %d\n", *foundValue);
            return 1;
        }
        hashInsert(&hashTable, currentMovie, currentMovie);
    }

    return 0;
}