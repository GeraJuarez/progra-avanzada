#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "booleanparser.h"

#define OR_SIZE 2
#define NOT_SIZE 3
#define AND_SIZE 3
#define TRUE_SIZE 4
#define FALSE_SIZE 5

void createBoolExpression(char* stringExp, char** boolExp) {
    int expLength = strlen(stringExp);
    char buf[100] = "";
    int bufCount = 0;
    char temp[5] = "";

    for (int i = 0; i < expLength; i++)
    {
        if (stringExp[i] >= 'A' && stringExp[i] <= 'Z')
        {
            memset(temp, 0, 5);

            if (stringExp[i] == 'N')
            // Looks for NOT
            {
                strncpy(temp, &stringExp[i], NOT_SIZE );
                if ( strcmp( temp, "NOT" ) == 0) 
                {
                    buf[bufCount] = '-';
                    bufCount++;
                    i += NOT_SIZE - 1;
                    continue;
                }
                memset(temp, 0, 5);
            }

            if (stringExp[i] == 'A')
            // Looks for AND
            {
                strncpy(temp, &stringExp[i], AND_SIZE );
                if ( strcmp( temp, "AND" ) == 0) 
                {
                    buf[bufCount] = '*';
                    bufCount++;
                    i += AND_SIZE - 1;
                    continue;
                }
                memset(temp, 0, 5);
            }

            if (stringExp[i] == 'T')
            // Looks for TRUE
            {
                strncpy(temp, &stringExp[i], TRUE_SIZE );
                if ( strcmp( temp, "TRUE" ) == 0) 
                {
                    buf[bufCount] = '1';
                    bufCount++;
                    i += TRUE_SIZE - 1;
                    continue;
                }
                memset(temp, 0, 5);
            }

            if (stringExp[i] == 'F')
            // Looks for FALSE
            {
                strncpy(temp, &stringExp[i], FALSE_SIZE );
                if ( strcmp( temp, "FALSE" ) == 0) 
                {
                    buf[bufCount] = '0';
                    bufCount++;
                    i += FALSE_SIZE - 1;
                    continue;
                }
                memset(temp, 0, 5);
            }

            if (stringExp[i] == 'O')
            // Looks for OR
            {
                strncpy(temp, &stringExp[i], OR_SIZE );
                if ( strcmp( temp, "OR" ) == 0) 
                {
                    buf[bufCount] = '+';
                    bufCount++;
                    i += OR_SIZE - 1;
                    continue;
                }
                memset(temp, 0, 5);
            }

        }
        if (stringExp[i] != ' ')
        {
            buf[bufCount] = stringExp[i];
            bufCount++;
        }
    }

    char* result = (char*) malloc( bufCount * sizeof(char) );
    strcpy( result, buf );
    *boolExp = result;
}

/* Parse tree */

void valuesInit(Value* v, char* boolExp, int* registers) {
    // Declare a struct with the bool expression and registers for global access
    v->expr = boolExp;
    v->regs = registers;
}

int parseAddition(Value*);

int parseAtom(Value* v) {
    int num = 0;        // Value to return
    int regIndex = 0;   // Normalized index of the registers
    int negation = 0;   // Flag for a negative sign

    if (*v->expr == '-')
    {
        negation = 1;
        *v->expr++;     // Advance the pointer
    }

    if (*v->expr == '(')
    // Handle operations under parenthesis
    {
        *v->expr++;
        int parenthesisRes = parseAddition(v);
        // Since it always recieve a coorrect bool expression
        // it is not necesary to check for unmatched parenthesis
        // At thist point v->expr is pointing to a rigth parenthesis ')'.
        *v->expr++;
        if (negation)
        {
            parenthesisRes = (parenthesisRes + 1) % 2;
        }
        return parenthesisRes;
    }

    // The pointer should now point to a letter(register A...Z) or value 1 or 0
    if (*v->expr == '1' || *v->expr == '0')
    {
        num = *v->expr - '0';
    }
    else
    {
        regIndex = (int)*v->expr - 65;      // Normalize the index
        num = v->regs[ regIndex ];          // Find current value of the register
    }
    if (negation)
    {
        num = (num + 1) % 2;                       // Do a negation (NOT 1 = 0, NOT 0 = 1)
    }
    *v->expr++;
    return num;
}

int parseMult(Value* v) {
    int num1 = parseAtom(v);
    while (1)
    {
        char op = *v->expr;                 // Get operator (* or +)
        if (op != '*')
        {
            return num1;
        }
        *v->expr++;
        int num2 = parseAtom(v);
        num1 *= num2;                       // AND operation
    }
}

int parseAddition(Value* v) {
    int num1 = parseMult(v);
    while (1)
    {
        char op = *v->expr;
        if (op != '+')
        {
            return num1;
        }
        *v->expr++;
        int num2 = parseMult(v);
        num1 = num1 || num2;                   // OR operation
    }
}

int evaluateBoolExpression(char* boolExp, int* registers) {
    int result = 0;
    Value values;
    valuesInit(&values, boolExp, registers);

    result = parseAddition(&values);

    return result;
}