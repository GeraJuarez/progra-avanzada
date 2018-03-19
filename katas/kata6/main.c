#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define abs(x) ((x) >= 0 ? (x) : -(x))

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int distanceToMove(int z, int limit)
{
    double toMove = (z - limit) / (double) 2;
    toMove = abs(toMove);
    toMove = ceil(toMove);
    return toMove;
}

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    
    // Init axis limits
    int minX = 0;
    int maxX = W;
    int minY = H;
    int maxY = 0;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        
        if (bombDir[0] == 'U')
        {
            minY = Y0;
            Y0 -= distanceToMove(Y0, maxY);
        }
        else if (bombDir[0] == 'D')
        {
            maxY = Y0;
            Y0 += distanceToMove(Y0, minY);
        }
        if (bombDir[0] == 'R' || bombDir[1] == 'R')
        {
            minX = X0;
            X0 += distanceToMove(X0, maxX);
        }
        if (bombDir[0] == 'L' || bombDir[1] == 'L')
        {
            maxX = X0;
            X0 -= distanceToMove(X0, minX);
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // the location of the next window Batman should jump to.
        printf("%d %d\n", X0, Y0);
    }

    return 0;
}