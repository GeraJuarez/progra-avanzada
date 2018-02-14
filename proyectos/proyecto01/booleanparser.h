typedef struct v {
    char* expr;
    int* regs;
} Value;

void createBoolExpression(char*, char**);
int evaluateBoolExpression(char*, int*);