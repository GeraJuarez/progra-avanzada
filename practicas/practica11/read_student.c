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

    data = fopen(studentDB, "rb");

    while(1)
    {
        fread(&myStudent, sizeof(Student), 1, data);
        if (feof(data))
        {
            break;
        }
        if (!strcmp(myStudent.lastName, lastName))
        {
            printf("name %s \n", myStudent.name);
            printf("last name %s \n", myStudent.lastName);
            printf("id %d \n", myStudent.id);
            printf("calif %d \n", myStudent.cal);
            break;
        }
    }

    fclose(data);
    return 0;
}