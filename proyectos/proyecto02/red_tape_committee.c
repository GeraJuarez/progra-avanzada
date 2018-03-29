#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "red_tape_committee.h"

#define PRINT_DEBUG(...)                                  \
    do                                                    \
    {                                                     \
        char* debug;                                      \
        debug = getenv("DEBUG");                          \
        if (debug != NULL && !strcasecmp(debug, "y"))     \
        {                                                 \
            fprintf(stderr, __VA_ARGS__);                 \
        }                                                 \
    } while (0)

double calculateTieProbability(double* probs, int size) {
    int K = size;

    // Init probability matrix with 0s
    double** probMatrix = (double**) calloc( K + 1, sizeof(double*) );
    for (int i = 0; i < K + 1; i++)
    {
        probMatrix[i] = (double*) calloc( K + 1, sizeof(double) );
    }

    // Init the first value
    probMatrix[0][0] = 1.0;

    for (int i = 0; i <= K / 2; i++)
    // Only half of the calculations is needed to get the tie probability
    {
        for (int j = i + 1; j <= K; j++)
        // Starting from [0][1] and using the current probability ([0][0])
        // calculate the NO probability in [0][1]
        // calculate the YES probability below (in [1][1])
        {
            double current_prob =  probMatrix[i][j - 1];
            probMatrix[i][j] += current_prob * (1 - probs[j - 1]);
            probMatrix[i + 1][j] += current_prob * (probs[j - 1]);
        }
    }

/*
    // Print the array
    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            printf("%f\t", probMatrix[i][j]);
        }
        printf("\n");
    }
*/
    return probMatrix[K / 2][K];
}

void selectMembers(double* probs, int sizeP, double** members, int sizeM)
// Probability array and its size; array of members of committee and its size
{
    // Init new Members
    double* newMembers = (double*) malloc(sizeM * sizeof(double));

    int min = 0;
    int max = sizeP - 1;

    for (int i = 0; i < sizeM; i++)
    {
        if (probs[min] >= 0.5)
        {
            PRINT_DEBUG("min 0.5\n");
            newMembers[i] = probs[min];
            min++;
        }
        else if (probs[max] <= 0.5)
        {
            PRINT_DEBUG("max 0.5\n");
            newMembers[i] = probs[max];
            max--;
        }
        else
        {
            PRINT_DEBUG("min and max 0.5\n");
            newMembers[i] = probs[min];
            newMembers[++i] = probs[max];
            min++;
            max--;
        }
    }

    // Assign the new members to the committe
    *members = newMembers;
}

void selectMembers_Sol2(double* probs, int sizeN,  double** committee, int sizeK, int count)
// Select the last K elements of the probs array and it moves 1 to the right ofr every iteration
// The count parameter increases from 0 to K
{
    // Init new Members
    double* newMembers = (double*) malloc(sizeK * sizeof(double));
    
    for (int i = 0; i < sizeK; i++)
    {
        // The '%' make the index to go back to the initia position
        // Something like a circular array
        int probsIndex = (sizeN - sizeK + i + count) % sizeN;
        newMembers[i] = probs[probsIndex];
    }

    *committee = newMembers;
}