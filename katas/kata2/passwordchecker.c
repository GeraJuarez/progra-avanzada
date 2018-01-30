#include <string.h>

int max(int a, int b) {
    /* Returns the grater number */
    if ( a > b) {
        return a;
    } 
    else {
        return b;
    }
}

int rule2Checker(char* s) {
    /* Looks for an uppercase char, a lowercase char and a digit */
    int ruleFaults = 3;
    int size = strlen(s);
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;

    for (int i = 0; i < size; i++)
    {
        if (!hasUpper && s[i] <= 'Z' && s[i] >= 'A')
        {
            hasUpper = 1;
        }
        else if (!hasLower && s[i] <= 'z' && s[i] >= 'a') 
        {
            hasLower = 1;
        }
        else if (!hasDigit && s[i] <= '9' && s[i] >= '0')
        {
            hasDigit = 1;
        }

    }
    ruleFaults = ruleFaults - hasUpper - hasLower - hasDigit;

    return ruleFaults;
}

int rule3Checker(char* s) {
    /* Looks for sequence of chars */
    int ruleFaults = 0;
    int size = strlen(s);
    int charCount = 0;
    char prevChar = ' ';
    char currentChar = ' ';

    prevChar = s[0];
    for (int i = 1; i < size; i++)
    {
        currentChar = s[i];
        if (currentChar == prevChar)
        {
            charCount++;
            if (charCount == 2)
            {
                ruleFaults++;
                charCount = 0;
                i++;
            }
        }
        else
        {
            charCount = 0;
        }
        prevChar = s[i];
    }

    return ruleFaults;
}

int strongPasswordChecker(char* s) {

    int size = strlen(s);
    int changes = 0;
    int rule2Faults = rule2Checker(s);
    int rule3Faults = rule3Checker(s);
    int offset = 0;

    if (size >= 6 && size <= 20)
    {
        if (rule2Faults && rule3Faults)
        {
            changes = max(rule2Faults, rule3Faults);
        }
        else if (rule2Faults)
        {
            changes = rule2Faults;
        }
        else if (rule3Faults)
        {
            changes = rule3Faults;
        }
    }
    else if (size < 6)
    {
        offset = 6 - size;
        if (rule2Faults && rule3Faults)
        {
            changes += rule3Faults;
            //changes += max( max(0,rule2Faults - rule3Faults), offset );
            changes += max(offset, rule2Faults);
        }
        else if (rule2Faults)
        {
            changes += max(rule2Faults, offset);
        }
        else if (rule3Faults)
        {
            changes += rule3Faults + offset;
        }
        else
        {
            changes += offset;
        }
    }
    else if (size > 20)
    {
        offset = size - 20;
        if (rule2Faults && rule3Faults)
        {
            changes += rule2Faults;
            changes += max( max(0,rule3Faults - rule2Faults), offset );
        }
        else if (rule2Faults)
        {
            changes += offset;
            changes += rule2Faults;
        }   
        else if (rule3Faults)
        {
            changes += max(rule3Faults, offset);
        }
        else 
        {
            changes += offset;
        }
    }

    return changes;
}