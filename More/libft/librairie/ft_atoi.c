
#include "../includes/libft.h"

static void		ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int				ft_atoi(const char *str)
{
	int					i;
	int					k;
	unsigned long long	n;

	i = 0;
	n = 0;
	k = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		(str[i++] == 45 ? k = -1 : k);
	if (i == (int)ft_strlen(str))
		ft_error();
	while (str[i] > 47 && str[i] < 58)
	{
		n = 10 * n + (str[i++] - 48);
		if ((n > 2147483647 && k == 1) || (n > 2147483648 && k == -1))
			ft_error();
	}
	if (i == 0 || i != (int)ft_strlen(str))
		ft_error();
	return ((int)n * k);
}
