#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_DEBUG(...)                                  \
    do                                                    \
    {                                                     \
        char* debug;                                      \
        debug = getenv("DEBUG");                          \
        if (debug != NULL && !strcasecmp(debug, "y"))     \
        {                                                 \
            fprintf(stderr, __VA_ARGS__);                 \
        }                                                 \
    } while (0)

int main () {
    // stdin: standard input, in this case, the keyboard
    // stdout: standard output, in this case, the console
    // stderr: standard output2, same as stdout
    /* 2> is the stdoutput 2, aka stderr */
    /* 1> is the stdoutput 1, aka stdout */
    /* >> is used to append to the selected file */
    
    // gcc input.c | ./input.exe 2> archivo.txt

    int character;

    while (1) 
    {
        character = fgetc(stdin);

        if (feof(stdin))
        {
            break;
        }
        fputc(character, stdout);
        PRINT_DEBUG("character = %c\n", character);
    }

    return 0;
}