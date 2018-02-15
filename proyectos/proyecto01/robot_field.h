typedef struct r {
    char facing;
    int* registers;
    int x;
    int y;
} Robot;

void initRobot(Robot*);
void changeDirection(Robot*, int);
void changeRegister(Robot*, char);
void moveForward(Robot*);