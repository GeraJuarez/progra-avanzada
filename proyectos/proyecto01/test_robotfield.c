#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "booleanparser.h"

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

static char* testCreateBoolExp() {
    char* boolExpression;
    char stringExp[] = "NOT((A OR NOT B) AND (A OR B)) OR NOT (A AND NOT B OR TRUE)";
    char result[] = "-((A+-B)*(A+B))+-(A*-B+1)";

    createBoolExpression(stringExp, &boolExpression);
    muAssert("test error", strcmp( result, boolExpression ) == 0);

    return 0;
}

static char* testEvaluateBoolExp() {
    int regs[26] = {0};

    char stringExp[] = "A+B";
    int expected = 0;
    int result = evaluateBoolExpression(stringExp, regs);
    muAssert("Error at evaluating expression", result == expected);

    char stringExp2[] = "A*-B";
    expected = 0;
    result = evaluateBoolExpression(stringExp2, regs);
    muAssert("Error at evaluating expression 2", result == expected);

    char stringExp3[] = "-A+-B*C";
    expected = 1;
    result = evaluateBoolExpression(stringExp3, regs);
    muAssert("Error at evaluating expression 3", result == expected);

    char stringExp4[] = "(A+-B)*(A+B)";
    expected = 0;
    result = evaluateBoolExpression(stringExp4, regs);
    muAssert("Error at evaluating expression 4", result == expected);

    char stringExp5[] = "-(A+1)*(0+B)+1";
    expected = 1;
    result = evaluateBoolExpression(stringExp5, regs);
    printf("%d\n", result);
    muAssert("Error at evaluating expression 5", result == expected);

    char stringExp6[] = "-((A+-B)*(A+B))+-(A*-B+1)";
    expected = 1;
    result = evaluateBoolExpression(stringExp6, regs);
    muAssert("Error at evaluating expression 6", result == expected);

    return 0;
}

static char* allTests() {
    muRunTest(testCreateBoolExp);
    muRunTest(testEvaluateBoolExp);

    return 0;
}

int main(int argc, char** argv) {
    char* result = allTests();
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
