
#include "../includes/libft.h"

int		ft_countwords(char const *s, char c)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			m++;
		i++;
	}
	return (m + 1);
}
