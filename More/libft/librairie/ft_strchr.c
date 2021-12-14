
#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;
	char	l;

	i = 0;
	j = 0;
	l = c;
	str = (char *)s;
	while (str[j] != '\0')
		j++;
	if (l == '\0')
		return (str + j);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == l)
		return (str + i);
	else
		return (0);
}
