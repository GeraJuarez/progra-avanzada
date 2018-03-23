#include <stdio.h>
#include <string.h>

typedef struct s {
    char name[20];
    char lastName[20];
    unsigned int id;
    char cal;
} Student;

int main() {
    char* studentDB = "studentDB.data";
    Student myStudent;
    char* lastName = "Perez2";
    FILE* data;

    data = fopen(studentDB, "r+b");

    while(1)
    {
        fread(&myStudent, sizeof(Student), 1, data);
        if (feof(data))
        {
            break;
        }
        if (!strcmp(myStudent.lastName, lastName))
        {
            sprintf(myStudent.name, "Pedro");
            fseek(data, -1 * sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
            break;
        }
    }

    fclose(data);
    return 0;
}