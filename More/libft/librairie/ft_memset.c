
#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*bb;
	unsigned char	cc;

	bb = b;
	cc = c;
	while (n > 0)
	{
		*bb++ = cc;
		n--;
	}
	return (b);
}
