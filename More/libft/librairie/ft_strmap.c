
#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
