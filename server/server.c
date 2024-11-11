#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

static void handle_sigusr1(int sig)
{
    (void)sig;
    ft_printf("SIGUSR1 received\n");
}

static void handle_sigusr2(int sig)
{
    (void)sig;
    ft_printf("SIGUSR2 received\n");
}

int main(void)
{
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    ft_printf("Server PID: %d\n", getpid());

    while (1)
        ;
}