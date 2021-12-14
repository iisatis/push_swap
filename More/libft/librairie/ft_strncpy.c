
#include "../includes/libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
			return (dest);
		}
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
