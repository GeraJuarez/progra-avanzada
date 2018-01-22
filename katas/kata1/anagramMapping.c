#include <stdio.h>
#include <stdlib.h>

/**
 * Kata 1: Find Anagram Mappings.
 * This program does not uses a hash table, it iterates over B for every
 * element in A.
 * 
 * Complexity: O(n^2).
 */ 

int anagramMapping( int * A, int * B, int ** P, int length )
{
    int * F = (int *) calloc( length, sizeof(int) );            // init F with 0s
    int * indexMap = (int *) malloc( length * sizeof(int) );    // init indexMap

    for ( int i = 0; i < length; i++ ) {
        // Iterate over A
        for ( int j = 0; j < length; j++ ) {
            // Iterate over B
            if ( A[i] == B[j] && !F[j]) {
                // Search A[i] in B[i] and check that index j have not been used
                indexMap[i] = j;
                F[j] = 1;
                break;
            }
        }
    }
    *P = indexMap;

    return 0;
}

int main()
{
    int a[] = {1, 3, 2, 3, 1, 0};             // array A
    int b[] = {3, 2, 1, 0, 3, 1};             // array B
    int * p;                                    // Init index mapping P
    int size = sizeof(a) / sizeof(int);         // Calculate length

    anagramMapping( a, b, &p, size );

    printf( "Array A and B:\n" );
    for ( int i = 0; i < size; i++ ) {
        // Print array A and B
        printf( "a[%d] = %d \t b[%d] = %d\n", i, a[i], i, b[i] );
    }
    printf( "Index Mapping P:\n" );
    for ( int i = 0; i < size; i++ ) {
        // Print results
        printf( "p[%d] = %d\n", i, p[i] );
    }

    free( p );

    return 0;
}