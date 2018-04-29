#include <stdlib.h>
#include <stdio.h>
#include "forbidden_sum.h"

int maximum(int * array, int size)
{
	int curr = 0;
	int max = 0;

	for (curr = 0; curr < size; curr++)
	{
		if(array[curr] > max)
		{ 
			max = array[curr]; 
		}
	}
	return max;
}

void countingSort(int* array, int size)
{
	int curr = 0;
	int max = maximum(array, size);
	int* counting_array = calloc(max, sizeof(int)); // Zeros out the array

	for (curr = 0; curr < size; curr ++)
	{
		counting_array[array[curr]]++;
	}

	int num = 0;
	curr = 0;

	while(curr <= size)
	{
		while(counting_array[num] > 0)
		{
			array[curr] = num;
			counting_array[num]--;
			curr++;

			if(curr > size)
			{ 
				break; 
			}
		}
		num++;
	}
}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int list[],int m,int n, int* indexArray)
{
    int key,i,j,k;
    if( m < n)
    {
        k = (m + n) / 2; // Pivot
        swap(&list[m],&list[k]);
		swap(&indexArray[m], &indexArray[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
			{
				swap(&list[i],&list[j]);
				swap(&indexArray[i], &indexArray[j]);
			}
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
		swap(&indexArray[m], &indexArray[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1, indexArray);
        quicksort(list,j+1,n, indexArray);
    }
}

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

int getForbiddenSum_sol2(int* array, int sizeN, int L, int R, int* indexArr)
// Assumes a sorted array
{
    int forbiddenSum = 0;
    int rangeSize = R - L + 1;
    int j = 0;
    for (int i = 0; i < sizeN; i++)
    {
        if (indexArr[i] <= R - 1 && indexArr[i] >= L - 1)
        {
            if (array[i] <= forbiddenSum + 1)
            {
                forbiddenSum += array[i];
                j++;
            }
            else break;
        }
        if (!(j < rangeSize))
        {
            break;
        }
    }

    return forbiddenSum + 1;
}