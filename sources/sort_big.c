/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:34:02 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/22 17:32:51 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_pile_b(t_env *piles, int pos)
{
	if (pos > 0)
	{
		while (pos > 1)
		{
			push_up_b(piles);
			pos--;
		}
	}
	else
	{
		while (pos < 0)
		{
			push_down_b(piles);
			pos++;
		}
	}
}

static void	push_back_a(t_env *piles, int size)
{
	int	pos;

	pos = up_or_down(size, size, piles->b);
	while (piles->b)
	{
		rotate_pile_b(piles, pos);
		push_a(piles);
		size--;
		if (size > 0)
			pos = up_or_down(size, size, piles->b);
	}
}

static void	rotate_pile_a(t_env *piles, int pos)
{
	if (pos > 0)
	{
		while (pos > 1)
		{
			push_up_a(piles);
			pos--;
		}
	}
	else
	{
		while (pos < 0)
		{
			push_down_a(piles);
			pos++;
		}
	}
}

void	sort_big(t_env *piles, int argc, int cut)
{
	int	pos;
	int	stack;
	int	size;

	cut = argc / cut;
	size = argc;
	stack = 1;
	pos = up_or_down(stack, (stack + cut), piles->a);
	while (size > 0)
	{
		while (pos && size > 0)
		{
			rotate_pile_a(piles, pos);
			push_b(piles);
			size--;
			if (size > 0)
				pos = up_or_down(stack, (stack + cut), piles->a);
		}
		stack += cut;
		if (size > 0)
			pos = up_or_down(stack, (stack + cut), piles->a);
	}
	push_back_a(piles, argc);
	while (piles->ops->prev)
		piles->ops = piles->ops->prev;
}
