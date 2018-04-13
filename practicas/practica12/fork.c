#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();

    if (pid == 0)
    {
        execl("/mnt/d/Zegerd/Practicas_Proyectos/progra_avanzada/practicas/practica12/hijo.exe",
        "hijo.exe", (char*)0);          // 1st arg: path; 2nd arg: name; 3rd arg: null
        printf("%s\n", "Hola hijo mundo");
    }
    else
    {
        printf("%s\n", "Hola padre mundo");
    }

    return 0;
}