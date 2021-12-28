/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:37:00 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/28 17:45:27 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_pile_a2(t_env *piles, int pos)
{
	while (pos != 0)
	{
		if (pos > 0)
		{
			push_up_a(piles);
			pos--;
		}
		else if (pos < 0)
		{
			push_down_a(piles);
			pos++;
		}
	}
}

static int	check_up(t_env *piles, int buff)
{
	int	up;

	up = 0;
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next && piles->a->pos != buff)
	{
		up++;
		piles->a = piles->a->next;
	}
	return (up);
}

static int	check_down(t_env *piles, int buff)
{
	int	down;

	down = 0;
	while (piles->a->next)
		piles->a = piles->a->next;
	while (piles->a->prev && piles->a->pos != buff)
	{
		down++;
		piles->a = piles->a->prev;
	}
	return (++down);
}

static int	check_pos(t_env *piles)
{
	int	pos_up;
	int	pos_down;
	int	buff;

	buff = 42;
	while (piles->a->next)
	{
		if (piles->a->pos > piles->b->pos && piles->a->pos < buff)
			buff = piles->a->pos;
		piles->a = piles->a->next;
	}
	if (piles->a->pos > piles->b->pos && piles->a->pos < buff)
		buff = piles->a->pos;
	if (buff == 42)
	{
		while (piles->a->prev && piles->a->prev->pos < piles->a->pos)
			piles->a = piles->a->prev;
		buff = piles->a->pos;
	}
	pos_up = check_up(piles, buff);
	pos_down = check_down(piles, buff);
	if (pos_up <= pos_down)
		return (pos_up);
	return (-pos_down);
}

void	sort_small(t_env *piles, int argc)
{
	int	pos;

	while (argc > 3)
	{
		push_b(piles);
		argc--;
	}
	sort_three(piles);
	while (piles->b)
	{
		while (piles->a->prev)
			piles->a = piles->a->prev;
		while (piles->b->prev)
			piles->b = piles->b->prev;
		pos = check_pos(piles);
		rotate_pile_a2(piles, pos);
		push_a(piles);
	}
	pos = up_or_down(1, 1, piles->a);
	rotate_pile_a(piles, pos);
}
