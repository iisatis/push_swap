
#include "../includes/push_swap.h"

void		ft_instruction(t_pile **inst, int n)
{
	t_pile		*e;
	t_pile		*new;

	e = *inst;
	if (e != NULL)
	{
		while (e->next != NULL)
			e = e->next;
		new = ft_pilenew(n);
		e->next = new;
	}
	else
		*inst = ft_pilenew(n);
}

static void	ft_print_instruction_2(t_pile *e)
{
	if (e->data == 3)
		ft_printf("pa\n");
	else if (e->data == 4)
		ft_printf("pb\n");
	else if (e->data == 5)
		ft_printf("ra\n");
	else if (e->data == 6)
		ft_printf("rb\n");
	else if (e->data == 7)
		ft_printf("rra\n");
	else if (e->data == 8)
		ft_printf("rrb\n");
}

static void	ft_print_instruction(t_begin *begin)
{
	t_pile		*e;
	t_pile		*suiv;

	e = begin->inst;
	while (e != NULL)
	{
		if (e->next != NULL)
			suiv = e->next;
		if (e->data == 1 && suiv && suiv->data != 2)
			ft_printf("sa\n");
		else if (e->data == 2 && suiv && suiv->data != 1)
			ft_printf("sb\n");
		else if ((e->data == 1 && suiv && suiv->data == 2)
				|| (e->data == 2 && suiv && suiv->data == 1))
		{
			ft_printf("ss\n");
			e = e->next;
		}
		else
			ft_print_instruction_2(e);
		e = e->next;
	}
}

int			ft_algo(t_begin *begin)
{
	int			n;

	n = ft_find_len(&begin->ba);
	if (n == 1)
		return (0);
	else if (n == 2)
		ft_sort_2_elem(begin);
	else if (n == 3)
		ft_sort_3_elem(begin);
	else
		ft_work_a(begin, ft_find_len(&begin->ba));
	ft_print_instruction(begin);
	return (0);
}
