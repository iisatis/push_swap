
#include "../includes/ft_printf.h"

char			*ft_itoaulgint(unsigned long int n)
{
	char			*nbr;
	int				i;
	unsigned long	nb;

	i = (n == 0 ? 1 : 0);
	nb = n;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	if (!(nbr = (char *)malloc(sizeof(char) * (i))))
		exit(0);
	nbr[i] = '\0';
	while (i--)
	{
		nbr[i] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}
