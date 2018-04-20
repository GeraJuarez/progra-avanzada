#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 20

int varGlobal;
sem_t sema;

void* helloWorld(void* p)
{
    long id = (long) p;    // Cast to desired value
    printf("%s : %ld\n", "Hello Worlds again, I am", id);
    sem_wait(&sema);
    varGlobal += 100;
    sem_post(&sema);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    long i;
    sem_init(&sema, 0, 1); // 0: semaphore for threads. 1: Initial value

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
        printf("%s = %d\n", "varGlobal", varGlobal);
    }

    return 0;
}