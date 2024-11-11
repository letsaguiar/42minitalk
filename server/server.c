#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

void handle_signal(int sig)
{
    printf("Caught signal %s\n", ft_itoa(sig));
    exit(0);
}

int main(void)
{
    signal(SIGINT, handle_signal);
    while (1)
        ;
}