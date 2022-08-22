#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
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

int	main(void)
{
	char	x[] = "1100001";
	printf("not mine	: %d\n", atoi(x));

	int	c = ft_atoi(x);
	printf("\n\nThe char	: %c\n\n", c);
	printf("mine		: %d\n", ft_atoi(x));
	return (0);
}
