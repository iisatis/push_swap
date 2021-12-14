
#include "../includes/libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char			*ft_strndup(const char *s1, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		n;

	i = 0;
	n = ft_min(ft_strlen(s1), len);
	if (!(ptr = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] && i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
