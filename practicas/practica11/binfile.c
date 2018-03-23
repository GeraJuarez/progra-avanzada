#include <stdio.h>

typedef struct s {
    char name[20];
    char lastName[20];
    unsigned int id;
    char cal;
} Student;

int main() {
    char* studentDB = "studentDB.data";
    FILE* data;
    Student pAvanzada[5];
    for (int i = 0; i < 5; i++)
    {
        sprintf(pAvanzada[i].name, "student%d", i);
        sprintf(pAvanzada[i].lastName, "Perez%d", i);
        pAvanzada[i].id = i * 20;
        pAvanzada[i].cal = i * 7;
    }

    data = fopen(studentDB, "wb"); // b: binary, open file as raw data
    fwrite(pAvanzada, sizeof(Student), 5, data);

    fclose(data);
    return 0;
}