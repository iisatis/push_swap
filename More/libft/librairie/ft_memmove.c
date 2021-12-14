
#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if ((src + n) >= dst && src < dst)
	{
		i = (n - 1);
		while (i > 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
		((char *)dst)[0] = ((char *)src)[0];
	}
	else
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
