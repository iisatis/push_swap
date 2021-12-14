
#include "../includes/ft_printf.h"

void	ft_putstrtot(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar(s[i]);
}
