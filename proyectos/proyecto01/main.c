#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "booleanparser.h"
#include "robot_field.h"

#define BOOLEXPR_SIZE 250

void solution1()
{
    char booleanExpression[BOOLEXPR_SIZE];
    int N = 0;      // field size
    int M = 0;      // number of forks
    int K = 0;      // number of register inverting points

    int* Mx;       // Forks position in x axis
    int* My;       // Forks position in y axis
    int* Kx;       // Register inverting points position in x axis
    int* Ky;       // Register inverting points position in y axis
    char* Kc;      // Register inverting points value to change

    // Read input
    scanf("%[^\n]s", booleanExpression);
    scanf("%d %d %d", &N, &M, &K);

    // Pupulate arrays
    Mx = (int*) calloc(M, sizeof(int));
    My = (int*) calloc(M, sizeof(int));
    Kx = (int*) calloc(K, sizeof(int));
    Ky = (int*) calloc(K, sizeof(int));
    Kc = (char*) calloc(K, sizeof(char));

    // Read Forks positions
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &Mx[i], &My[i]);
    }

    // Read Register inverting points
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %c", &Kx[i], &Ky[i], &Kc[i]);
    }

    // Init robot values and parsed bool expression
    char* parsedBoolExpr;
    createBoolExpression(booleanExpression, &parsedBoolExpr);
    Robot robot;
    initRobot(&robot);
    int exprResult = 0;

    do
    {
        printf("%d %d\n", robot.x, robot.y);

        for (int i = 0; i < M; i++)
        // Look for a Fork
        {
            if (robot.x == Mx[i])
            {
                if (robot.y == My[i])
                {
                    exprResult = evaluateBoolExpression(parsedBoolExpr, robot.registers);
                    changeDirection(&robot, exprResult);
                    break;
                }
            }
        }

        for (int i = 0; i < K; i++)
        // Looks for a register inverting point
        {
            if (robot.x == Kx[i])
            {
                if (robot.y == Ky[i])
                {
                    changeRegister(&robot, Kc[i]);
                    break;
                }
            }
        }
        moveForward(&robot);

    } while (robot.x <= 1 && robot.y <= 1);
}

void solution2()
{
    char booleanExpression[BOOLEXPR_SIZE];
    int N = 0;      // field size
    int M = 0;      // number of forks
    int K = 0;      // number of register inverting points

    char** field;   // Field representation

    // Read input
    scanf("%[^\n]s", booleanExpression);
    scanf("%d %d %d", &N, &M, &K);

    // Init field
    field = (char**) calloc((N * 2) + 1, sizeof(char*));
    for (int i = 0; i < (N * 2) + 1; i++)
    {
        field[i] = (char*) calloc((N * 2) + 1, sizeof(char));
    }

    // Read Forks positions
    int xPos, yPos;
    char reg;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &xPos, &yPos);
        field[xPos + N][yPos + N] = '1';
    }

    // Read Register inverting points
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %c", &xPos, &yPos, &reg);
        field[xPos + N][yPos + N] = reg;
    }

    // Init robot values and parsed bool expression
    char* parsedBoolExpr;
    createBoolExpression(booleanExpression, &parsedBoolExpr);
    Robot robot;
    initRobot(&robot);
    int exprResult = 0;
    char currentPos;

    do
    {
        printf("%d %d\n", robot.x, robot.y);
        currentPos = field[robot.x + N][robot.y + N];
        if (currentPos)
        {
            if (currentPos == '1')
            // Fork found
            {
                exprResult = evaluateBoolExpression(parsedBoolExpr, robot.registers);
                changeDirection(&robot, exprResult);
            }
            else
            // Register inverting point found
            {
                changeRegister(&robot, currentPos);
            }
        }
        moveForward(&robot);

    } while (robot.x <= 1 && robot.y <= 1);
}

int main()
{
    //solution1();
    solution2();

    return 0;
}