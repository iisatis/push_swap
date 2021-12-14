
#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str;
	s2 = (char *)to_find;
	while (s2[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s2[i] == '\0')
		return (s1);
	if (s1[i] == '\0')
		return (0);
	return (ft_strstr(++s1, s2));
}
