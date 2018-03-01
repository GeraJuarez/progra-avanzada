#include <string.h>
#include <stdio.h>

#define isDigit(d) (d >= '0' && d <= '9')

typedef struct s {
    char *input;
    int index;
    int size;
} StateInfo;

void initStateInfo(StateInfo* si, char* inputString)
{
    si->input = inputString;
    si->index = 0;
    si->size = strlen(inputString);
}

int state13(StateInfo* s)
{
    s->index += 1;
    char currentChar;

    while (s->index < s->size)
    // Read the whole remaining characters
    // At this point, the number ended and the program is looking for empty spaces
    {
        currentChar = s->input[s->index];

       if (currentChar != ' ')
        {
            return 0;
        }

        s->index += 1;
    }
    return 1;
}

int state12(StateInfo* s)
{
    s->index += 1;
    char currentChar;

    while (s->index < s->size)
    // Reading after the 'e' was found, at this point only digits are valid
    {
        currentChar = s->input[s->index];

        if (currentChar == ' ')
        {
            return state13(s);
        }
        else if (!isDigit(currentChar))
        {
            return 0;
        }

        s->index += 1;
    }
    return 1;
}

int state11(StateInfo* s)
{
    // At this point, and 'e' was found

    s->index += 1;
    char currentChar = s->input[s->index];

    if (currentChar == '+' || currentChar == '-')
    // Looks for a sign
    {
        // Go to next char
        s->index += 1;
        currentChar = s->input[s->index];
    }

    if (isDigit(currentChar))
    {
        return state12(s);   
    }
    else
    // Something else that is not a number, including another sign
    {
        return 0;
    }
}

int state10(StateInfo* s)
{
    s->index += 1;
    char currentChar;

    while (s->index < s->size)
    {
        currentChar = s->input[s->index];

        if (currentChar == 'e')
        {
            return state11(s);
        }
        else if (currentChar == ' ')
        {
            return state13(s);
        }
        else if (!isDigit(currentChar))
        // Any other symbol invalidates the number
        {
            return 0;
        }

        s->index += 1;
    }
    // When the loop ends, only numbers where found, hence a valid number
    return 1;
}

int state9(StateInfo* s)
{
    s->index += 1;
    char currentChar = s->input[s->index];

    // Start the decimal part, the next char must be a digit to continue
    if (isDigit(currentChar))
    {
        return state10(s);   
    }
    else
    {
        return 0;
    }
}

int state4(StateInfo* s)
{
    s->index += 1;

    char currentChar;
    int digitCount = 0;

    while (s->index < s->size)
    {
        currentChar = s->input[s->index];

        if (isDigit(currentChar))
        {
            // Keep track of numbers read before a coma
            // There must be three digist before any other symbol
            digitCount++;
            if (digitCount > 3)
            {
                return 0;
            }
        }
        else if (currentChar == ',' && digitCount == 3)
        // Keep reading numbers with coma
        {
            return state4(s);
        }
        else if (currentChar == '.' && digitCount == 3)
        // Starts the decimal part
        {
            return state9(s);
        }
        else if (currentChar == 'e' && digitCount == 3)
        // Starts the exponent part
        {
            return state11(s);
        }
        else if (currentChar == ' ' && digitCount == 3)
        // No numbers to read, look for spaces
        {
            return state13(s);
        }
        else
        // Any invalid symbol for numbers
        {
            return 0;
        }
        s->index += 1;
    }
    // When the loop ends, only numbers where found
    // If there are no three digist after a coma, is an incomplete number
    return (digitCount == 3) ? 1 : 0;
}

int state1_3(StateInfo* s)
{

    s->index += 1;

    char currentChar;
    int digitCount = 1;

    while (s->index < s->size)
    {
        currentChar = s->input[s->index];

        if (isDigit(currentChar))
        {
            // Turns off a flag to identify whether the number uses coma to separe numbers
            digitCount = (digitCount > 3) ? digitCount + 1 : digitCount;
        }
        else if (currentChar == ',' && digitCount <= 3)
        // If a coma is found, go to a state that manages numbers with coma
        // When digitCount is over 3, that means that the number does not uses coma to separate umbers
        {
            return state4(s);
        }
        else if (currentChar == '.')
        // Start the decimal part
        {
            return state9(s);
        }
        else if (currentChar == 'e')
        // Start the exponent part
        {
            return state11(s);
        }
        else if (currentChar == ' ')
        // Go to the end and looks for spaces
        // This means the number ended
        {
            return state13(s);
        }
        else
        // Any symbol that invalidates the number
        {
            return 0;
        }

        s->index += 1;
    }
    // When the loop ends, only numbers where found, hence a valid number
    return 1;
}

int state0(StateInfo* s)
{
    char currentChar;
    int signedNumber = 0;

    while (s->index < s->size)
    {
        currentChar = s->input[s->index];   

        if (isDigit(currentChar))
        // Go to next state if a digit is found
        {
            return state1_3(s);
        }
        else if (currentChar == '.')
        // Jump to the state for the decimal parte
        {
            return state9(s);
        }
        else if ( (currentChar == '+' || currentChar == '-') && !signedNumber)
        // Check for symbols '+' and '-'
        {
            signedNumber = 1;
        }
        else if (currentChar != ' ')
        // Looks for spaces after the number
        {
            return 0;
        }

        s->index += 1;      // Read next char
    }
    return 0;
}

int isValidNumber(char* s)
{
    StateInfo si;
    initStateInfo(&si, s);

    int result = 1;

    result = state0(&si);
    
    return result;
}