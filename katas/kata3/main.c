#include <stdio.h>
#include <string.h>
#include <assert.h>

int judgeRouteCicle(char* moves) {
    int x = 0;
    int y = 0;
    int moveSize = strlen(moves);

    for ( int i = 0; i < moveSize; i++ ) {
        assert( moves[i] == 'U' ||
                moves[i] == 'D' ||
                moves[i] == 'L' ||
                moves[i] == 'R'
        );
        if (moves[i] == 'U') {
            y++;
        } 
        else if (moves[i] == 'D') {
            y--;
        }
        else if (moves[i] == 'R') {
            x++;
        }
        else if (moves[i] == 'L') {
            x--;
        }
    }

    int isCicle = (x == 0 && y == 0);

    return isCicle;
}

int main() {
    char moves[200];
    printf("%s\n", "Insert robot's movement");
    scanf("%s", moves);

    if (judgeRouteCicle(moves))
    {
        printf("%s\n", "true");
    } 
    else 
    {
        printf("%s\n", "false");
    }
    
    return 0;
}