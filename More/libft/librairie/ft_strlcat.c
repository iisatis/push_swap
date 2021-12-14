
#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	k = ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	if (size != 0)
	{
		while (src[j] != '\0' && i < size - 1)
			dst[i++] = src[j++];
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (k + i - j);
	}
	return (k + i);
}
