#include <stdlib.h>
#include <stdio.h>
#include "forbidden_sum.h"

int getForbiddenSum(int* array, int size)
// Assumes a sorted array
{
    int forbiddenSum = 0;

    for(int i = 0; i < size; i++)
    {
        if (array[i] <= forbiddenSum + 1)
        {
            forbiddenSum += array[i];
        }
        else break;
    }

    return forbiddenSum + 1;
}