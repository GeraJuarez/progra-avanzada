typedef struct e {
    int key;
    int value;
} Element;

typedef struct d {
    Element* elements;
    unsigned count;
    unsigned length;
} HashElement;

typedef struct h {
    HashElement* data;
    unsigned size;
} HashInt;

void hashInit(HashInt*, unsigned);

void hashInsert(HashInt*, int, int);

int* hashGet(HashInt*, int);