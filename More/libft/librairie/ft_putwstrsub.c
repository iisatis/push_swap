
#include "../includes/ft_printf.h"

void	ft_putwstrsub(wchar_t *s, int k)
{
	int		i;

	i = 0;
	while (*s && i < k)
	{
		ft_putwchar(*s);
		i = i + ft_wsize(*s);
		s++;
	}
}
