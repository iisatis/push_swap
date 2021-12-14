
#include "../includes/checker.h"

t_pile	*ft_swap_pile(t_pile **bi)
{
	t_pile		*elem;
	int			tmp;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	tmp = elem->next->data;
	elem->next->data = elem->data;
	elem->data = tmp;
	*bi = elem;
	return (*bi);
}

t_pile	*ft_push_pile(t_pile **bf, t_pile **bi)
{
	t_pile		*elem;

	elem = *bi;
	if (elem == NULL)
		return (*bf);
	elem->next = *bf;
	*bf = elem;
	return (*bf);
}

t_pile	*ft_rotate_pile(t_pile **bi)
{
	t_pile		*elem;
	int			tmp;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	tmp = elem->data;
	while (elem->next != NULL)
	{
		elem->data = elem->next->data;
		elem = elem->next;
	}
	elem->data = tmp;
	return (*bi);
}

t_pile	*ft_reverse_rotate_pile(t_pile **bi)
{
	t_pile		*elem;
	int			tmp0;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	while (elem->next != NULL)
		elem = elem->next;
	tmp0 = elem->data;
	ft_rr(bi);
	elem = *bi;
	elem->data = tmp0;
	return (*bi);
}

void	ft_check_pile(t_pile **bi, t_pile **bb)
{
	t_pile	*elem;
	int		n;

	elem = *bi;
	if (elem != NULL)
	{
		n = elem->data;
		elem = elem->next;
	}
	while (elem != NULL)
		if (elem->data > n)
		{
			n = elem->data;
			elem = elem->next;
		}
		else
		{
			ft_printf("KO\n");
			exit(0);
		}
	elem = *bb;
	if (elem == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
