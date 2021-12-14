
#include "../includes/ft_printf.h"

char	*ft_strzero(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		exit(0);
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
