/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:17:52 by kkalika           #+#    #+#             */
/*   Updated: 2022/08/29 19:23:22 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	if (!c)
		exit(EXIT_FAILURE);
	write(1, &c, 1);
}

void	ft_putnbr(long long i)
{
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar((i % 10) + '0');
}

void	ft_handle_sig(int signum)
{
	static unsigned char	sig = '\0';
	static int				count_bit = 8;

	if (signum == SIGUSR1)
		sig = sig | 0;
	else if (signum == SIGUSR2)
		sig = sig | 1;
	else
		exit(EXIT_FAILURE);
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

int	main(void)
{
	pid_t				mypid;
	struct sigaction	my_act;

	mypid = getpid();
	write(STDOUT_FILENO, "This is my PID: ", 17);
	ft_putnbr(mypid);
	write(STDOUT_FILENO, "\n", 1);
	my_act.sa_handler = &ft_handle_sig;
	my_act.sa_flags = SA_SIGINFO | SA_NODEFER;
	if (sigaction(SIGUSR1, &my_act, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &my_act, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
