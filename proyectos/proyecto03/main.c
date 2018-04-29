#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "forbidden_sum.h"

int compare (const void * a, const void * b)
// Used to compare usign the quick sort
{
    if ( *(int*)a > *(int*)b )
	{
		return 1;
	}
    else if ( *(int*)a < *(int*)b )
	{
		return -1;
	}
    else 
		return 0;
}

int main() {
	int N, M, i, L, R, forbSum, tempSize;
	int* A;
	int* x;

	scanf("%d", &N);
	A = (int*) malloc( N * sizeof(int) );
	x = (int*) malloc( N * sizeof(int) );

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	scanf("%d", &M);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &L, &R);
		tempSize = R - L + 1;
		memcpy(x, A + L - 1, sizeof(int) * tempSize);
		qsort(x, tempSize, sizeof(int), compare);
		forbSum = getForbiddenSum(x, tempSize);
		printf("%d\n", forbSum);
	}

	free(x);
	free(A);
	return 0;
}