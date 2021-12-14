
#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	int			i;
	size_t		n;

	i = 0;
	n = ft_strlen(s1);
	if (!(ptr = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
