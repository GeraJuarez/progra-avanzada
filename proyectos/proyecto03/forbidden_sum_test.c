#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "forbidden_sum.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

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

static char* forbiddenSum() {
	int size, result, expected;

	int a[] = {1, 1, 3, 7};
	expected = 6;
	size = sizeof(a) / sizeof(int);

	result = getForbiddenSum(a, size);

  	muAssert("error, Forbidden sum 1", expected == result);

	int b[] = {1, 2, 4, 9, 10};
	expected = 8;
	size = sizeof(b) / sizeof(int);

	result = getForbiddenSum(b, size);

  	muAssert("error, Forbidden sum 2", expected == result);
  	return 0;
}


static char* arraySubset() {
	int* x;
	int size, L, R;
	x = (int*) malloc(10 * sizeof(int));

	int a[] = {1, 2, 4, 9, 10};
	size = sizeof(a) / sizeof(int);

	// Test 1
	L = 1;
	R = 2;
	memcpy(x, a + L - 1, sizeof(int) * (R - L + 1));

	muAssert("error, Array subset 1.0", x[0] == a[0]);
	muAssert("error, Array subset 1.1", x[1] == a[1]);

	// Test 2
	L = 3;
	R = 5;
	memcpy(x, a + L - 1, sizeof(int) * (R - L + 1));

	muAssert("error, Array subset 2.0", x[0] == a[2]);
	muAssert("error, Array subset 2.1", x[1] == a[3]);
	muAssert("error, Array subset 2.1", x[2] == a[4]);
	return 0;
}

static char* sortRangeArray()
{
	int* x;
	int size, L, R;
	x = (int*) malloc(10 * sizeof(int));

	int a[] = {10, 3, 4, 9, 5};
	size = sizeof(a) / sizeof(int);

	// Test 1
	L = 1;
	R = 2;
	memcpy(x, a + L - 1, sizeof(int) * (R - L + 1));
	qsort(x, R - L + 1, sizeof(int), compare);

	muAssert("error, Array sort 1.0", x[0] == 3);
	muAssert("error, Array sort 1.1", x[1] == 10);

	// Test 2
	L = 3;
	R = 5;
	memcpy(x, a + L - 1, sizeof(int) * (R - L + 1));
	qsort(x, R - L + 1, sizeof(int), compare);

	muAssert("error, Array sort 2.0", x[0] == 4);
	muAssert("error, Array sort 2.1", x[1] == 5);
	muAssert("error, Array sort 2.2", x[2] == 9);
	return 0;
}

static char* allTests() {
  	muRunTest(forbiddenSum);
	muRunTest(arraySubset);
	muRunTest(sortRangeArray);

  	return 0;
}

int main(int argc, char **argv) {
	char *result = allTests();
  	if (result != 0) {
    	printf("-_-_-_-_-_-_-_,------,      o \n");
      	printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
      	printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
      	printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
      	printf(KRED "✗ %s \n" RESET, result);
	}
  	else {
      	printf("-_-_-_-_-_-_-_,------,      o \n");
      	printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
      	printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
      	printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
      	printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  	}
  	printf("Tests run: %d\n", testsRun);
  	return result != 0;
}
