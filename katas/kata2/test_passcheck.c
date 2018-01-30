#include <stdio.h>
#include "passwordchecker.h"

void printTestMsg(int, char *, char *);

int main()
{
    int a, b, result, expected;
    char* s;

    // Test max
    a = 10;
    b = 2;
    result = max(a, b);
    expected = 10;
    printTestMsg(result == expected,
                 "Max test passed",
                 "Max test failed");

    // Test max 2
    a = 0;
    b = -2;
    result = max(a, b);
    expected = 0;
    printTestMsg(result == expected,
                 "Max test 2 passed",
                 "Max test 2 failed");

    // Rule 2 test
    s = "hola";
    result = rule2Checker(s);
    expected = 2;
    printTestMsg(result == expected,
                 "Rule2 test passed",
                 "Rule2 test failed");

    // Rule 2 test 2
    s = "Hola";
    result = rule2Checker(s);
    expected = 1;
    printTestMsg(result == expected,
                 "Rule2 test 2 passed",
                 "Rule2 test 2 failed");

    // Rule 2 test 3
    s = "Hol1a";
    result = rule2Checker(s);
    expected = 0;
    printTestMsg(result == expected,
                 "Rule2 test 3 passed",
                 "Rule2 test 3 failed");

    // Rule 3 test
    s = "hola";
    result = rule3Checker(s);
    expected = 0;
    printTestMsg(result == expected,
                 "Rule3 test passed",
                 "Rule3 test failed");

    // Rule 3 test 2
    s = "holaaa";
    result = rule3Checker(s);
    expected = 1;
    printTestMsg(result == expected,
                 "Rule3 test 2 passed",
                 "Rule3 test 2 failed");

    // Rule 3 test 3
    s = "hhhoooolllllaaaaaa";
    result = rule3Checker(s);
    expected = 5;
    printTestMsg(result == expected,
                 "Rule3 test 3 passed",
                 "Rule3 test 3 failed");

    // Strong Pass Check Test 1
    s = "H0la123";
    result = strongPasswordChecker(s);
    expected = 0;
    printTestMsg(result == expected,
                 "SPC test 1 passed",
                 "SPC test 1 failed");

    // Strong Pass Check Test 2
    s = "oooad";
    result = strongPasswordChecker(s);
    expected = 3;
    printTestMsg(result == expected,
                 "SPC test 2 passed",
                 "SPC test 2 failed");

    // Strong Pass Check Test 3
    s = "oooLA";
    result = strongPasswordChecker(s);
    expected = 2;
    printTestMsg(result == expected,
                 "SPC test 3 passed",
                 "SPC test 3 failed");

    // Strong Pass Check Test 4
    s = "oooL5";
    result = strongPasswordChecker(s);
    expected = 2;
    printTestMsg(result == expected,
                 "SPC test 4 passed",
                 "SPC test 4 failed");

    // Strong Pass Check Test 5
    s = "ooo";
    result = strongPasswordChecker(s);
    expected = 4;
    printTestMsg(result == expected,
                 "SPC test 5 passed",
                 "SPC test 5 failed");

    // Strong Pass Check Test 6
    s = "A000";
    result = strongPasswordChecker(s);
    expected = 3;
    printTestMsg(result == expected,
                 "SPC test 6 passed",
                 "SPC test 6 failed");

    // Strong Pass Check Test 7
    s = "01113456789123456789aa";
    result = strongPasswordChecker(s);
    expected = 3;
    printTestMsg(result == expected,
                 "SPC test 7 passed",
                 "SPC test 7 failed");

    // Strong Pass Check Test 8
    s = "01013456789123456789aa";
    result = strongPasswordChecker(s);
    expected = 3;
    printTestMsg(result == expected,
                 "SPC test 8 passed",
                 "SPC test 8 failed");

    // Strong Pass Check Test 9
    s = "A1013456789123456789aa";
    result = strongPasswordChecker(s);
    expected = 2;
    printTestMsg(result == expected,
                 "SPC test 9 passed",
                 "SPC test 9 failed");

    // Strong Pass Check Test 10
    s = "0001115678912345678911";
    result = strongPasswordChecker(s);
    expected = 4;
    printTestMsg(result == expected,
                 "SPC test 10 passed",
                 "SPC test 10 failed");

    // Strong Pass Check Test 11
    s = "00011155589123456789aA11";
    result = strongPasswordChecker(s);
    expected = 4;
    printTestMsg(result == expected,
                 "SPC test 11 passed",
                 "SPC test 11 failed");

    return 0;
}

void printTestMsg(int testResult,
                  char *passedMsg,
                  char *failedMsg)
{
    if (testResult)
    {
        printf("%s\n", passedMsg);
    }
    else
    {
        printf("%s\n", failedMsg);
    }
}