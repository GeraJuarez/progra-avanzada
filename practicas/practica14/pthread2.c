#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 20

void* helloWorld(void* p)
{
    long id = (long) p;    // Cast to desired value
    char* msg = (char*) malloc(32 * sizeof(char));
    sprintf(msg, "%s : %ld\n", "Hello Worlds again, I am", id);

    return (void*)msg;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    long i;
    char* msg;

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
            (void*)&msg
        );
        printf("%s", msg);
        free(msg);
    }

    return 0;
}