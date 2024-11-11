#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

static void handle_sigusr1(int sig)
{
    (void)sig;
    ft_putstr_fd("SIGUSR1 received\n", 1);
}

static void handle_sigusr2(int sig)
{
    (void)sig;
    ft_putstr_fd("SIGUSR2 received\n", 1);
}

int main(void)
{
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    while (1)
        ;
}