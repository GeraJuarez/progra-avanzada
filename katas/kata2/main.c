#include <stdio.h>
#include "passwordchecker.h"

int main() 
{
    char password[200];
    printf("%s\n%s\n", "Check whether your password is strong", "Write a password:");
    scanf("%s", password);
    printf("%s %d %s\n", "Your password needs:", strongPasswordChecker(password), "changes");

    return 0;
}