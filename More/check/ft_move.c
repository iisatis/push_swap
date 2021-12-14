
#include "../includes/checker.h"

void			ft_move2(char *str, t_begin *begin)
{
	if (str && (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0))
		begin->ba = ft_rotate_pile(&begin->ba);
	else if (str && (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0))
		begin->ba = ft_reverse_rotate_pile(&begin->ba);
	else if (str && (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0))
		begin->bb = ft_rotate_pile(&begin->bb);
	else if (str && (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0))
		begin->bb = ft_reverse_rotate_pile(&begin->bb);
	else if (str && (ft_strcmp(str, "ss") == 0))
	{
		begin->ba = ft_swap_pile(&begin->ba);
		begin->bb = ft_swap_pile(&begin->bb);
	}
	else if ((str && (ft_strcmp(str, "pa") == 0) && begin->bb == NULL)
			|| (str && (ft_strcmp(str, "pb") == 0) && begin->ba == NULL))
		return ;
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void			ft_move(char *str, t_begin *begin)
{
	t_pile		*tmp;

	if (str && (ft_strcmp(str, "sa") == 0))
		begin->ba = ft_swap_pile(&begin->ba);
	else if (str && (ft_strcmp(str, "sb") == 0))
		begin->bb = ft_swap_pile(&begin->bb);
	else if (str && (ft_strcmp(str, "pa") == 0) && begin->bb != NULL)
	{
		tmp = begin->bb->next;
		begin->ba = ft_push_pile(&begin->ba, &begin->bb);
		begin->bb = tmp;
	}
	else if (str && (ft_strcmp(str, "pb") == 0) && begin->ba != NULL)
	{
		tmp = begin->ba->next;
		begin->bb = ft_push_pile(&begin->bb, &begin->ba);
		begin->ba = tmp;
	}
	else
		ft_move2(str, begin);
}
