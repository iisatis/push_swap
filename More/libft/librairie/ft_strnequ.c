
#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
			i++;
		if (i == n && s1[i - 1] == s2[i - 1])
			return (1);
		if ((s1[i] == '\0' || s2[i] == '\0') && s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
