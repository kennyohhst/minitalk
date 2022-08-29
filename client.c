#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		x;

	s = (char *) str;
	i = 0;
	x = 0;
	if (!str)
		return (0);
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		return (0);
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		return (0);
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		x = (x * 10) + (s[i] - '0');
		i++;
	}
	return (x);
}

void	ft_send_bit(int n, int count, int pid)
{
	int killcheck;

	killcheck = 0;
	if (count == 0)
		return;
	ft_send_bit(n >> 1, count - 1, pid);
	if (!(n & 1))
		killcheck = kill(pid, SIGUSR1);
	else
		killcheck = kill(pid, SIGUSR2);
	if (killcheck < 0)
	{
		write(STDOUT_FILENO, "Error, check PID", 17);
		exit(1);
	}
	usleep(500);
}

int main(int argc, char **argv)
{
	int i;
	int pid;
	
	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (write(STDOUT_FILENO, "NOT ENOUGH ARGUMENTS", 21));
	if (pid <= 0)
		return (write(STDOUT_FILENO, "PID ERROR", 10));
	while (argv[2][i] != '\0')
	{
		ft_send_bit(argv[2][i], 8, pid);
		i++;
	}
	return (0);
}
