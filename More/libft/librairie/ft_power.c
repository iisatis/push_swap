
#include "../includes/libft.h"

long	ft_power(int nb, int power)
{
	long n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		n = n * ft_power(n, power - 1);
	return (n);
}
