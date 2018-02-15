#include <stdio.h>
#include <stdlib.h>
#include "robot_field.h"

#define NORTH 'N'
#define SOUTH 'S'
#define EAST 'E'
#define WEST 'W'

#define ALPHABET_SIZE 26
#define NORMALIZE_VALUE 65

void initRobot(Robot* r)
{
    r->facing = EAST;
    r->x = 0;
    r->y = 0;
    r->registers = (int*) calloc(ALPHABET_SIZE, sizeof(int));
}

char turnRight(char dir) {
    if (dir == NORTH)
    {
        return EAST;
    }
    else if (dir == SOUTH)
    {
        return WEST;
    }
    else if (dir == EAST)
    {
        return SOUTH;
    }
    else // WEST
    {
        return NORTH;
    }
}

char turnLeft(char dir) {
        if (dir == NORTH)
    {
        return WEST;
    }
    else if (dir == SOUTH)
    {
        return EAST;
    }
    else if (dir == EAST)
    {
        return NORTH;
    }
    else // WEST
    {
        return SOUTH;
    }
}

void changeDirection(Robot* r, int boolRes) {
    if (boolRes)
    {
        r->facing = turnRight(r->facing);
    }
    else
    {
        r->facing = turnLeft(r->facing);
    }
}

void changeRegister(Robot* r, char regToChange)
{
    int index = regToChange - NORMALIZE_VALUE;
    r->registers[index] = !r->registers[index];
}

void moveForward(Robot* r)
{
    if (r->facing == NORTH)
    {
        r->y++;
    }
    else if (r->facing == SOUTH)
    {
        r->y--;
    }
    else if (r->facing == EAST)
    {
        r->x++;
    }
    else if (r->facing == WEST)
    {
        r->x--;
    }
}