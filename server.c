#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

void	convert(char *str)
{
	char	*s;
	int		i;
	int		x;
	int		neg;

	s = (char *) str;
	i = 0;
	x = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	while (s[i] && (s[i] == '0' || s[i] == '1'))
	{
		x = (x * 2) + (s[i] - 48);
		i++;
	}
	return (x);
}

void    ft_handle_sig(int signum)
{
	char	*str;
	int		i;

	i = 0;
	str = calloc(8, sizeof(char));
	if (!str)
		return ;
	if (signum == SIGUSR1)
        str[i] = '0';
	if (signum == SIGUSR2)    
        str[i] = '1';
	i++;
	
	if (i == 8)
	{
		free(str);
		return (convert(str));
	}
}

int main(void)
{
    pid_t               mypid;
    struct sigaction    my_act;

    mypid = getpid();


    printf("This is my PID: %d\n", mypid);

    while (1)
	{
	    my_act.sa_handler = &ft_handle_sig;
	    sigaction(SIGUSR1, &my_act, NULL);
	    sigaction(SIGUSR2, &my_act, NULL);
        pause();
	}
}