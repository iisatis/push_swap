/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:34:02 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/19 18:24:48 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push_b(t_env *piles)
{
	t_pile	*temp;

	temp = piles->a->next;
	piles->a->next = piles->b;
	piles->b = piles->a;
	piles->a = temp;
	new_op(piles, 2);
	return;
}

static void	push_up_a(t_env piles)
{
	t_pile	*temp;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	temp = piles->a;
	piles->a = piles->a->next;
	piles->a->prev = NULL;
	temp->next = NULL;
	while (piles->a->next)
		piles->a = piles->a->next;
	temp->prev = piles->a;
	piles->a->next = temp;
	return;
}

static void	push_down_a(t_env piles)
{
	t_pile	*temp;

	while (piles->a->next)
		piles->a = piles->a->next;
	temp = piles->a;
	piles->a = piles->a->prev;
	piles->a->next = NULL;
	temp->prev = NULL;
	while (piles->a->prev)
		piles->a = piles->a->prev;
	temp->next = piles->a;
	piles->a->prev = temp;
	return;
}

static void	rotate_pile_a(t_env *piles, int pos)
{
	if (pos > 0)
		while (pos > 1)
		{
			push_up_a(piles);
			new_op(piles, 3);
			pos--;
		}
	else
		while (pos < 0)
		{
			push_down_a(piles);
			new_op(piles, 6);
			pos++;
		}
	return;
}

t_cmd	*sort_big(t_env *piles, int argc)
{
	int 	pos;
	int		stack;

	stack = 1;
	pos = up_or_down(stack, stack + 20, piles);
	while (argc > 0)
	{
		while (pos && argc > 0)
		{
			rotate_pile_a(piles, pos);
			push_b(piles);
			argc--;
			pos = up_or_down(stack, stack + 20, piles);
		}
		stack += 20;
		pos = up_or_down(stack, stack + 20, piles);
	}
	while (ops->prev)
		ops = ops->prev;
	return (ops);
}
