#include <stdlib.h>
#include <stdio.h>
#include "red_tape_committee.h"

int compare (const void * a, const void * b)
// Used to compare usign the quick sort
{
    if ( *(double*)a > *(double*)b )
	{
		return 1;
	}
    else if ( *(double*)a < *(double*)b )
	{
		return -1;
	}
    else 
		return 0;
}

int main() {
    int testCases;
    int N;					// Size of the department
    int K;					// Size of the committee
	double maxResult;		// Used to save the maximum probability calculated
	double result;			// Keep the temporal results
	double* probs;			// Array of probabilities (department array)
	double* committee;		// Array of the chosen ones
    FILE* fileInput = freopen("data/B-large-practice.in", "r", stdin);
    FILE* fileResult = freopen("data/B-large-practice-result.txt", "w+", stdout);

    scanf("%d", &testCases);	// Read the number of test cases given

    for (int tests = 1; tests <= testCases; tests++)
    {
		scanf("%d %d", &N, &K);	// Read N and K
		
		// Init the department array
		probs = (double*) malloc (N * sizeof(double));

		for (int i = 0; i < N; i++)
		// Read every probability into the department array
		{
			scanf("%lf", &probs[i]);
		}

		// Sort the department array in non-decreasing order
		qsort(probs, N, sizeof(double), compare);
		maxResult = 0;

		// Select members
		for (int i = 0; i <= K; i++)
		{
			selectMembers_Sol2(probs, N, &committee, K, i);
			result = calculateTieProbability(committee, K);
			if (result > maxResult) {
				maxResult = result;
			}
		}

		printf("Case #%d: %.8lf\n", tests, maxResult);
		free(probs);
		free(committee);
    }
    
    return 0;
}