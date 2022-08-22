#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

//assign number to SIGUSR1 / SIGUSR2
void	sigusr_assign(int i, int pid)
{
	if (i == 0)
	{
		kill(pid, SIGUSR1);
		write(1, "0", 2);
		write(1, "\n", 1);

	}
	if (i == 1)
	{
		kill(pid, SIGUSR2);
		write(1, "1", 2);
		write(1, "\n", 1);
	}
	usleep(50);
}

//change nbr into binary
void	ft_putnbr_fd(int n, int pid)
{
	if (n >= 2)
		ft_putnbr_fd(n / 2, pid);
	sigusr_assign(n % 2, pid);
}

int main(int argc, char **argv)
{
	int i;
	int pid;
	
	
	i = 0;
	pid = atoi(argv[1]);
	// printf("%s\n", argv[2]);
	// kill(pid, SIGUSR2);
	// if (argc == 3)
		// printf("first : %s\nsecond : %s\nturd: %s\n", argv[0], argv[1], argv[2]);

	while (argv[2][i] != '\0')
	{
		ft_putnbr_fd(argv[2][i], pid);		
		i++;
	}
	// printf("this went better than expected :'D \n");

	return (0);
}