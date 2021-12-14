
#include "../includes/push_swap.h"

static void	ft_check_doublon(char **argv, int i, int n)
{
	i--;
	while (i > 0)
	{
		if (n == ft_atoi(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i--;
	}
}

void		ft_check_doublon_str(int *tab, int i, int n)
{
	int		j;

	j = (i != 0 ? i - 1 : 0);
	while (j >= 0)
	{
		if (tab[i] == tab[j] && n != 1 && j != i)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j--;
	}
}

t_pile		*ft_build_pile(int argc, char **argv)
{
	t_pile		*ea;
	t_pile		*ba;
	int			n;
	int			i;

	ea = NULL;
	ba = NULL;
	i = argc - 1;
	while (i > 0)
	{
		n = ft_atoi(argv[i]);
		ft_check_doublon(argv, i, n);
		ea = ft_pilenew(n);
		ea->next = ba;
		ba = ea;
		i--;
	}
	return (ba);
}
