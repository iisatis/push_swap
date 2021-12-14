
#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	l;
	char	*str;

	i = 0;
	l = c;
	str = (char *)s;
	while (str[i] != '\0')
		i++;
	i--;
	if (l == '\0')
		return (str + i + 1);
	while (i > 0 && str[i] != l)
		i--;
	if (str[i] == l)
		return (str + i);
	else
		return (0);
}
