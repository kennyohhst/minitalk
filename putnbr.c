#include <stdio.h>

//assign number to SIGUSR1 / SIGUSR2
void	sigusr_assign(int i)
{
	if (i == 0)
		kill(pid, SIGUSR1)
		// printf("IT WAS ZEROOOO : %d\n", i);
	if (i == 1)
		// printf("IT WAS ONEEEEE : %d\n", i);
}

//change nbr into binary
void	ft_putnbr_fd(int n)
{
	if (n >= 2)
		ft_putnbr_fd(n / 2);
	sigusr_assign(n % 2);
}



int	main(void)
{
	ft_putnbr_fd('a');
	return (0);
}