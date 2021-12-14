
#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = start;
	j = 0;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (j < len)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	else
		return (0);
}
