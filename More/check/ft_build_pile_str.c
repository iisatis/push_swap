
#include "../includes/push_swap.h"

static int		ft_count(char *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i] != '\0')
			i++;
		else if (((s[i] > 47 && s[i] < 58) || s[i] == 43 || s[i] == 45)
			&& (i == 0 || s[i - 1] == ' ') && s[i] != '\0')
		{
			i++;
			k++;
		}
		else if ((s[i] < 48 || s[i] > 57) && s[i] != 32 && s[i] != 43
				&& s[i] != 45)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else if (s[i] > 47 && s[i] < 58 && s[i] != '\0')
			i++;
	}
	return (k);
}

static char		*ft_find_number(char *str, int j)
{
	int		k;
	int		p;
	char	*s;

	k = 0;
	p = j;
	while (str[j] == ' ' && str[j] != '\0')
	{
		j++;
		p++;
	}
	while (((str[j] > 47 && str[j] < 58) || str[j] == 43 || str[j] == 45)
			&& str[j] != '\0')
	{
		j++;
		k++;
	}
	s = ft_strsub(str, p, k);
	return (s);
}

static int		ft_next_number(char *str, int j)
{
	while (str[j] == ' ' && str[j] != '\0')
		j++;
	while (((str[j] > 47 && str[j] < 58) || str[j] == 43 || str[j] == 45)
			&& str[j] != '\0')
		j++;
	return (j);
}

static int		*ft_fill_tab(char *str, int n)
{
	int		*tab;
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		exit(1);
	while (i < n)
	{
		s = ft_find_number(str, j);
		j = ft_next_number(str, j);
		tab[i] = ft_atoi(s);
		free(s);
		i++;
	}
	return (tab);
}

t_pile			*ft_build_pile_str(char *argv)
{
	t_pile		*ea;
	t_pile		*ba;
	int			i;
	int			*tab;

	ea = NULL;
	ba = NULL;
	i = ft_count(argv);
	if (i == 0)
		exit(0);
	tab = ft_fill_tab(argv, i);
	i--;
	while (i >= 0)
	{
		ft_check_doublon_str(tab, i, ft_count(argv));
		ea = ft_pilenew(tab[i]);
		ea->next = ba;
		ba = ea;
		i--;
	}
	free(tab);
	return (ba);
}
