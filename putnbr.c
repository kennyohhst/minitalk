#include <stdio.h>

//assign number to SIGUSR1 / SIGUSR2
char	*sigusr_assign(int i)
{

}

//change nbr into binary
void	ft_putnbr_fd(int n)
{
	if (n >= 2)
		ft_putnbr_fd(n / 2);
	sigusr_assign((n % 10) + '0');
}



int	main(void)
{
	ft_putnbr('a', 2);
	return (0);
}