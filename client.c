#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int	ft_putnbr(int i, int base)
{
	if (i >= base)
	{
		ft_putnbr(i / base, base);
	}
	return (i % base);

}

int main(int argc, char **argv)
{
	int i;
	i = 0;
	
	
	if (argc == 3)
		printf("first : %s\nsecond : %s\nturd: %s\n", argv[0], argv[1], argv[2]);

	int pid = atoi(argv[1]);

	ft_putnbr((long long) atoi(argv[2][i]), 2, 0);
	
	
	// printf("this happened with kill: %d\n ", kill(pid, SIGUSR1));
	
	printf("this went better than expected :'D \n");
    // while (1)
        // pause();
}