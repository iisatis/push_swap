/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:32:47 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/19 19:10:56 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	push_a(t_env *piles);
{
	t_pile	*temp;

	while (piles->b->prev)
		piles->b = piles->b->prev;
	temp = piles->b->next;
	piles->b->next = piles->a;
	piles->a = piles->b;
	piles->b = temp;
	new_op(piles, 1);
	return;
}

static void	push_up_b(t_env *piles)
{
	t_pile	*temp;

	while (piles->b->prev)
		piles->b = piles->b->prev;
	temp = piles->b;
	piles->b = piles->b->next;
	piles->b->prev = NULL;
	temp->next = NULL;
	while (piles->b->next)
		piles->b = piles->b->next;
	temp->prev = piles->b;
	piles->b->next = temp;
	return;
}

static void	push_down_b(t_env *piles)
{
	t_pile	*temp;

	while (piles->b->next)
		piles->b = piles->b->next;
	temp = piles->b;
	piles->b = piles->b->prev;
	piles->b->next = NULL;
	temp->prev = NULL;
	while (piles->b->prev)
		piles->b = piles->b->prev;
	temp->next = piles->b;
	piles->b->prev = temp;
	return;
}

static void	rotate_pile_b(t_env *piles, int pos)
{
	if (pos > 0)
		while (pos > 1)
		{
			push_up_b(piles);
			new_op(piles, 4);
			pos--;
		}
	else
		while (pos < 0)
		{
			push_down_b(piles);
			new_op(piles, 7);
			pos++;
		}
	return;
}

void	push_back_a(t_env *piles, int size)
{
	int 	pos;

	pos = up_or_down(size, size, piles->b);
	while (piles->b)
	{
		while (pos && piles->b)
		{
			rotate_pile_b(piles, pos);
			push_a(piles);
			pos = up_or_down(size, size, piles->b);
		}
		size--;
		pos = up_or_down(size, size, piles->b);
	}
	return;
}