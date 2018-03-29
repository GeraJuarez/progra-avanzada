#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minunit.h"
#include "red_tape_committee.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

#define EPSILON 0.00001

int compareDecimalEq(double a, double b)
{
    return fabs(a - b) < ( EPSILON * fabs(a + b) );
}

int compare (const void * a, const void * b)
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

int testsRun = 0;

static char * testProbabilityTie() {
	double res;
	double expected;
	int size;

	double a[] = {0.1, 0.2};
	size = sizeof(a) / sizeof(double); 

	res = calculateTieProbability(a, size);
	expected = 0.26;

	printf("result: %f\n", res);
	printf("expected: %f\n", expected);
  	muAssert("error, Test 1 result is not the expected", res == expected);

	double b[] = {0.0, 1.0};
	size = sizeof(b) / sizeof(double); 

	res = calculateTieProbability(b, size);
	expected = 1.0;

	printf("result: %lf\n", res);
	printf("expected: %f\n", expected);
  	muAssert("error, Test 2 result is not the expected", compareDecimalEq(res, expected));

	double c[] = {0.49, 0.49, 0.49, 0.50, 0.52, 0.54};
	size = sizeof(c) / sizeof(double); 

	res = calculateTieProbability(c, size);
	expected = 0.312675;

	printf("result: %f\n", res);
	printf("expected: %f\n", expected);
  	muAssert("error, Test 3 result is not the expected", compareDecimalEq(res, expected));

  	return 0;
}

static char * testSelectCommitteeMembers() {
	
	int size;
	int K;
	double* committee;

	// Test 1
	double a[] = {0.02, 0.68, 0.04, 0.67, 0.65, 0.64, 0.62, 0.61, 0.68, 0.66, 0.65, 0.65, 0.02, 0.02, 0.66, 0.67};
	K = 4;
	size = sizeof(a) / sizeof(double);

	// sort the array a
	qsort(a, size, sizeof(double), compare);

	selectMembers(a, size, &committee, K);

  	muAssert("error, Test select committee 1 result 0 is not the expected", compareDecimalEq(committee[0], 0.02));
	muAssert("error, Test select committee 1 result 1 is not the expected", compareDecimalEq(committee[1], 0.68));
	muAssert("error, Test select committee 1 result 2 is not the expected", compareDecimalEq(committee[2], 0.02));
	muAssert("error, Test select committee 1 result 3 is not the expected", compareDecimalEq(committee[3], 0.68));

	// Test 2
	double b[] = {0.49, 0.52, 0.54, 0.49, 0.52, 0.49, 0.51, 0.50, 0.52, 0.50, 0.50, 0.54, 0.54, 0.52, 0.52, 0.50};
	K = 6;
	size = sizeof(b) / sizeof(double);

	// sort the array a
	qsort(b, size, sizeof(double), compare);

	selectMembers(b, size, &committee, K);

  	muAssert("error, Test select committee 2 result 0 is not the expected", compareDecimalEq(committee[0], 0.49));
	muAssert("error, Test select committee 2 result 1 is not the expected", compareDecimalEq(committee[1], 0.54));
	muAssert("error, Test select committee 2 result 2 is not the expected", compareDecimalEq(committee[2], 0.49));
	muAssert("error, Test select committee 2 result 3 is not the expected", compareDecimalEq(committee[3], 0.54));
	muAssert("error, Test select committee 2 result 4 is not the expected", compareDecimalEq(committee[4], 0.49));
	muAssert("error, Test select committee 2 result 5 is not the expected", compareDecimalEq(committee[5], 0.54));

	// Test 3
	double c[] = {0.00, 0.00, 1.00, 1.00, 0.00, 1.00, 1.00, 0.00};
	K = 2;
	size = sizeof(c) / sizeof(double);

	// sort the array a
	qsort(c, size, sizeof(double), compare);

	selectMembers(c, size, &committee, K);

	for (int i = 0; i < K; i++)
	{
		printf("%lf\n", committee[i]);
	}

  	muAssert("error, Test select committee 1 result 0 is not the expected", compareDecimalEq(committee[0], 0.0));
	muAssert("error, Test select committee 1 result 1 is not the expected", compareDecimalEq(committee[1], 1.0));
	//muAssert("error, Test select committee 1 result 2 is not the expected", compareDecimalEq(committee[2], 0.0));
	//muAssert("error, Test select committee 1 result 3 is not the expected", compareDecimalEq(committee[3], 1.0));

  	return 0;
}

static char * allTests() {
  	muRunTest(testProbabilityTie);
	//muRunTest(testSelectCommitteeMembers);

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
