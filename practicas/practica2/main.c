#include <stdio.h>
#include "operations.h"

int main()
{
    char operation[200];
    int operator1, operator2;
    printf("%s\n", "What is the operation?");
    scanf("%s", operation);
    scanf("%d %d", &operator1, &operator2);
    printf("result: %d\n", add( operator1, operator2 ));

    return 0;
}