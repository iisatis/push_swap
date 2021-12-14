
#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str;
	s2 = (char *)to_find;
	if (s2[i] == '\0')
		return (s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
			if (s2[j] == '\0')
				return (s1 + i);
		}
		i++;
	}
	return (NULL);
}
