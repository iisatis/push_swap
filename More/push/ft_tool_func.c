
#include "../includes/push_swap.h"

int		ft_find_len(t_pile **bi)
{
	t_pile		*elem;
	int			i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

int		ft_is_sort(t_pile **begin, int pile)
{
	int		i;
	t_pile	*e;
	t_pile	*next;

	i = 0;
	e = *begin;
	next = e->next;
	while (i < ft_find_len(begin) - 1)
	{
		if ((e->data < next->data && pile == 1)
			|| (e->data > next->data && pile == 2))
		{
			e = e->next;
			next = e->next;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

void	ft_sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;
	int		n;

	i = 0;
	n = i;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = n;
		}
		else
			i++;
	}
	i = n;
}

int		ft_median(t_pile **begin, int pile, int n)
{
	t_pile	*tmp;
	int		i;
	int		*tab;
	int		len;
	int		median;

	i = 0;
	len = n;
	if (!(tab = (int *)malloc(sizeof(int) * (len + 1))))
		exit(1);
	tmp = *begin;
	while (i < len)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, len);
	if (pile == 2 && len % 2 == 0)
		median = tab[(len / 2) - 1];
	else
		median = tab[(len / 2)];
	free(tab);
	return (median);
}

int		ft_compare_with_median(t_begin *begin, int n, int median, int pile)
{
	int		i;
	t_pile	*elem;

	i = 0;
	if (pile == 1)
		elem = begin->ba;
	else if (pile == 2)
		elem = begin->bb;
	while (i < n)
	{
		if (pile == 1 && elem->data < median)
			return (1);
		if (pile == 2 && elem->data > median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}
