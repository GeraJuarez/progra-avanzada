#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct s {
    char name[20];
    char lastName[20];
    unsigned int id;
    char cal;
} Student;

int main()
// mmap: Maps data on disk to data on memory and synchronize them when the one on memory is changed
// munmap: closes the mapping
{
    char* filename = "studentDB.data";
    int fd = open(filename, O_RDWR);
    Student* pAvanzada = (Student*) mmap(
        NULL,
        5 * sizeof(Student),
        PROT_READ | PROT_WRITE,
        MAP_FILE | MAP_PRIVATE,
        fd,
        0
        );

    // close(fd);
    printf("Firs student %s\n", pAvanzada[0].name);
    strcpy(pAvanzada[1].name, "PedroPaz");
    munmap(pAvanzada, 5 * sizeof(Student));

    return 0;
}