/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:22:51 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/22 17:32:51 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_env *piles)
{
	t_pile	*temp;

	if (piles->a)
		while (piles->a->prev)
			piles->a = piles->a->prev;
	while (piles->b->prev)
		piles->b = piles->b->prev;
	temp = piles->b->next;
	piles->b->next = piles->a;
	if (piles->a)
		piles->a->prev = piles->b;
	piles->a = piles->b;
	piles->b = temp;
	if (piles->b)
		piles->b->prev = NULL;
	new_op(piles, 1);
}

void	push_up_b(t_env *piles)
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
	new_op(piles, 4);
}

void	push_down_b(t_env *piles)
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
	new_op(piles, 7);
}
