
#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (i < n && ss1[i] == ss2[i])
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
