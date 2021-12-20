/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:34:02 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/19 19:10:56 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push_b(t_env *piles)
{
	t_pile	*temp;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (piles->b)
		while (piles->b->prev)
			piles->b = piles->b->prev;
	temp = piles->a->next;
	piles->a->next = piles->b;
	if(piles->b)
		piles->b->prev = piles->a;
	piles->b = piles->a;
	piles->a = temp;
	if (piles->a)
		piles->a->prev = NULL;
	new_op(piles, 2);
	return;
}

static void	push_up_a(t_env *piles)
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

static void	push_down_a(t_env *piles)
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

t_cmd	*sort_big(t_env *piles, int argc, int cut)
{
	int pos;
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
	return (piles->ops);
}
