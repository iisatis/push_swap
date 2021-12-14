
#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	cc;
	char	*str;

	i = 0;
	cc = c;
	str = (char *)s;
	while (i < n && str[i] != cc)
		i++;
	if (i == n)
		return (NULL);
	else
		return (str + i);
}
