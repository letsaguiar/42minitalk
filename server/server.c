#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig)
{
    printf("Caught signal %d\n", sig);
    exit(0);
}

int main(void)
{
    signal(SIGINT, handle_signal);
    while (1)
        ;
}