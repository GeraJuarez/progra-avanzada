#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

void* helloWorld(void* p)
{
    long id = (long) p;    // Cast to desired value
    printf("%s : %ld\n", "Hello Worlds again, I am", id);

    // Para psasr un valor, se debe allocar enn la memoria con malloc
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    long i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create (
            &threads[i],
            NULL,           // atributos del hilo
            helloWorld,     // function
            (void*)i        // arg of function, disguise as void*
        );
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join (
            threads[i],
            NULL
        );
    }

    return 0;
}

// To compile use:
// gcc -o pthread.exe pthread.c -lpthread
// -l arg is used for non standard libs
