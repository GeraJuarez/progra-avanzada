#include <stdio.h>
#include <signal.h>

int noFinish = 1;
void processSignal(int signal)
{
    printf("Got signal: %d\n", signal);
    noFinish = 0;
}

int main()
{
    signal(SIGUSR1, processSignal);
    while(noFinish)
    {

    }
    return 0;
}