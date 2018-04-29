#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "forbidden_sum.h"

void sol1() 
{
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
		countingSort(x, tempSize);
		forbSum = getForbiddenSum(x, tempSize);
		printf("%d\n", forbSum);
	}

	free(x);
	free(A);
}

void sol2()
{
	int N, M, i, L, R, forbSum;
	int* A;
	int* x;

	scanf("%d", &N);
	A = (int*) malloc( N * sizeof(int) );
	x = (int*) malloc( N * sizeof(int) );

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		x[i] = i;
	}

	quicksort(A, 0, N - 1, x);
	scanf("%d", &M);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &L, &R);
		forbSum = getForbiddenSum_sol2(A, N, L, R, x);
		printf("%d\n", forbSum);
	}

	free(x);
	free(A);
}

int main()
{
	//sol1();
	sol2();
	
	return 0;
}