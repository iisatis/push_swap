
#include "../includes/push_swap.h"

t_pile		*ft_pilenew(int n)
{
	t_pile		*new;

	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		exit(0);
	new->data = n;
	new->next = NULL;
	return (new);
}

t_begin		*ft_init_begin(void)
{
	t_begin		*begin;

	if (!(begin = (t_begin*)malloc(sizeof(t_begin))))
		exit(1);
	ft_bzero(begin, sizeof(t_begin));
	return (begin);
}

void		ft_lstdel2(t_pile **begin)
{
	t_pile	*tmp;

	while (*begin != NULL)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	free(*begin);
}

void		ft_rr(t_pile **bi)
{
	t_pile		*elem;
	int			tmp;
	int			tmp2;
	int			i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		if (i % 2 != 0)
		{
			tmp2 = elem->data;
			elem->data = tmp;
		}
		else if (i % 2 == 0)
		{
			tmp = elem->data;
			elem->data = tmp2;
		}
		i++;
		elem = elem->next;
	}
}
