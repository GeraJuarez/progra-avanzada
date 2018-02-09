#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct a {
    double* data;
    int dataSize;
    int position;
} Array;

void appendArray(Array* a, double value)
{
    if (a->data == NULL) 
    {
        a->dataSize = 1;
        a->position = 0;
        a->data = (double*) malloc(a->dataSize * sizeof(double));
    }

    if ( a->position == a->dataSize )
    {   
        a->dataSize = 2 * a->dataSize;
        a->data = (double*) realloc( a->data, a->dataSize * sizeof(double) );
    }

    a->data[a->position] = value;
    a->position = a->position + 1;
}

void printReverseArray(Array a)
{
    for (int i = a.position - 1; i >= 0; i--)
    {
        printf("%.4lf \n", a.data[i]);
    }

}

int main()
{
    long Ai = 0;
    int c;
    Array results;
    results.data = NULL;
    
    do
    {
        c = getchar();
        while (!isdigit(c))
        {
            c = getchar();
        }

        Ai = 0;

        while ( isdigit(c) )
        {
            Ai = Ai * 10;
            Ai = Ai + (c - '0');
            c = getchar();
        }

        appendArray( &results, sqrt((double)Ai) );
        
    } while (c != 10); // new line (LF line field)

    printReverseArray(results);

    return 0;
}