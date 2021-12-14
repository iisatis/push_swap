
#include "../includes/ft_printf.h"

static char		*ft_basex(void)
{
	char	*base;
	int		i;

	i = 0;
	if (!(base = (char *)malloc(sizeof(char) * 17)))
		exit(0);
	while (i < 16)
	{
		if (i < 10)
			base[i] = 48 + i;
		else
			base[i] = 87 + i;
		i++;
	}
	base[i] = '\0';
	return (base);
}

static char		*ft_basexx(void)
{
	char	*base;
	int		i;

	i = 0;
	if (!(base = (char *)malloc(sizeof(char) * 17)))
		exit(0);
	while (i < 16)
	{
		if (i < 10)
			base[i] = 48 + i;
		else
			base[i] = 55 + i;
		i++;
	}
	base[i] = '\0';
	return (base);
}

static char		*ft_baseo(void)
{
	char	*base;
	int		i;

	i = 0;
	if (!(base = (char *)malloc(sizeof(char) * 9)))
		exit(0);
	while (i < 8)
	{
		base[i] = 48 + i;
		i++;
	}
	base[i] = '\0';
	return (base);
}

static char		*ft_baseoo(void)
{
	char	*base;
	int		i;

	i = 0;
	if (!(base = (char *)malloc(sizeof(char) * 9)))
		exit(0);
	while (i < 8)
	{
		base[i] = 48 + i;
		i++;
	}
	base[i] = '\0';
	return (base);
}

char			*ft_base(t_flag *arg)
{
	char	*base;

	base = NULL;
	if (arg->co == 'x' || arg->co == 'p')
	{
		if (!(base = ft_basex()))
			exit(0);
	}
	else if (arg->co == 'X')
	{
		if (!(base = ft_basexx()))
			exit(0);
	}
	else if (arg->co == 'o')
	{
		if (!(base = ft_baseo()))
			exit(0);
	}
	else if (arg->co == 'O')
	{
		if (!(base = ft_baseoo()))
			exit(0);
	}
	return (base);
}
