#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
		write(1, &c, 1);
}

void	ft_putnbr(long long i)
{
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar((i % 10) + '0');
}

void    ft_handle_sig(int signum)
{
	static unsigned char	sig = '\0';
	static int				count_bit = 8;

	if (signum == SIGUSR1)
		sig = sig | 0;
	else
		sig = sig | 1;
	count_bit--;
	if (count_bit == 0)
	{
		write(STDOUT_FILENO, &sig, 1);
		count_bit = 8;
		sig = '\0';
	}
	else
		sig <<= 1;
}

int main(void)
{
    pid_t               mypid;
    struct sigaction    my_act;

    mypid = getpid();
	write(STDOUT_FILENO, "This is my PID: ", 17);
	ft_putnbr(mypid);
	write(STDOUT_FILENO, "\n", 1);
    while (1)
	{
		my_act.sa_handler = &ft_handle_sig;
		my_act.sa_flags = SA_SIGINFO | SA_NODEFER;
	    sigaction(SIGUSR1, &my_act, NULL);
	    sigaction(SIGUSR2, &my_act, NULL);
        pause();
	}
	return (0);
}
