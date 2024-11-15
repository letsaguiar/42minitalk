#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

static unsigned int counter = 0;
static char letter = '\0';

static void addCounter()
{
    if (counter == 7)
    {
        ft_printf("%c", letter);
        counter = 0;

        if (letter == '\0')
            ft_printf("\n");
        letter = '\0';
    }
    else
        counter++;
}

static void handle_sigusr1(int sig)
{
    (void)sig;
    letter |= (1 << counter);
    addCounter();
}

static void handle_sigusr2(int sig)
{
    (void)sig;
    addCounter();
}

int main(void)
{
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    ft_printf("Server PID: %d\n", getpid());

    while (1)
        ;
}