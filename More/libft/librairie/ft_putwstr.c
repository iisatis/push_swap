
#include "../includes/libft.h"

void	ft_putwstr(wchar_t *s)
{
	while (*s)
	{
		ft_putwchar(*s);
		s++;
	}
}
