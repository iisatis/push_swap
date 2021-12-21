/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:37:00 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/21 18:58:30 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_two(t_env *piles)
{
		while (piles->a->prev)
			piles->a = piles->a->prev;
	if (piles->a->pos > piles->a->next->pos)
		switch_a(piles);
	return;
}

static void sort_three(t_env *piles)
{
	int	f;
	int	s;
	int	t;

	f = piles->a->pos;
	s = piles->a->next->pos;
	t = piles->a->next->next->pos;
	if (f > s && s < t && t > f)
		switch_a(piles);
	else if (f > s && s < t && t < f)
		push_up_a(piles);
	else if (f < s && s > t && t < f)
		push_down_a(piles);
	else if (f > s && s > t && t < f)
	{
		switch_a(piles);
		push_down_a(piles);
	}
	else if (f < s && s > t && t > f)
	{
		switch_a(piles);
		push_up_a(piles);
	}
	return;
}

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
	return ;
}

static int	check_pos(t_env *piles)
{
	int	pos_up;
	int	pos_down;

	pos_up = 0;
	pos_down = 1;
	while (piles->b->prev)
		piles->b = piles->b->prev;
	while (piles->a->pos < piles->b->pos && piles->a->next)
	{
		piles->a = piles->a->next;
		pos_up++;
	}
	while (piles->a->next)
		piles->a = piles->a->next;
	while (piles->a->pos > piles->b->pos && piles->a->prev)
	{
		piles->a = piles->a->prev;
		pos_down++;
	}
	if (pos_up <= pos_down)
		return (pos_up);
	return (-pos_down);
}

void	sort_small (t_env *piles, int argc)
{
	int	pos;

	while(argc > 3)
	{
		push_b(piles);
		argc--;
	}
	sort_three(piles);
	while (piles->b)
	{
		pos = check_pos(piles);
		rotate_pile_a2(piles, pos);
		push_a(piles);
	}
	pos = up_or_down(1, 1, piles->a);
	rotate_pile_a2(piles, pos);
	return ;
}
