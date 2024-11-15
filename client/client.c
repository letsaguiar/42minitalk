#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

static void send_message(int server_pid, t_string message)
{
    int size = ft_strlen(message);

    int i = 0;
    while (i <= size)
    {
        int j = 0;
        while (j < 8)
        {
            if (message[i] & (1 << j))
                kill(server_pid, SIGUSR1);
            else
                kill(server_pid, SIGUSR2);
            j++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr_fd("Usage: ./client [server-pid] [message]\n", 1);
        return (1);
    }

    int server_pid = ft_atoi(argv[1]);
    if (!server_pid)
    {
        ft_putstr_fd("Invalid server PID\n", 1);
        return (1);
    }

    t_string message = argv[2];
    send_message(server_pid, message);
}