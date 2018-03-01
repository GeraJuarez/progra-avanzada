#include <stdio.h>
#include "validnumber.h"

#define MAX_SIZE 256

int main()
{   
    char input[MAX_SIZE];
    int result = 0;
    scanf("%[^\n]s", input);
    result = isValidNumber(input);
    if (result)
    {
        printf("%s\n", "true");
    }
    else
    {
        printf("%s\n", "false");
    }

    return 0;
}