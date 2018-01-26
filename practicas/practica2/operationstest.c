#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char*, char*);

int main()
{
    // Test addition
    int a = 2147483644;
    int b = 2;
    int result = add(a, b);
    int expected = a + b; // El valor esperado puede ser harcodeado.
    printTestMessage(result == expected,
                     "Addition test failed",
                     "Addition test failed");

    // Test substraction
    int c = 2147483644;
    int d = 2;
    int resultSubstraction = substraction(c, d);
    int expectedSubstraction = c - d;
    printTestMessage(resultSubstraction == expectedSubstraction,
                     "Substraction test passed",
                     "Substraction test failed");

    return 0;
}

void printTestMessage(int testResult,
                      char* passedMessage,
                      char* failedMessage)
{

    if (testResult)
    {
        printf("%s\n", passedMessage);
    }
    else
    {
        printf("%s\n", failedMessage);
    }
}