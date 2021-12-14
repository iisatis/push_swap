
#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	n;
	char	*str;

	n = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	else
		return (0);
}
