/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:09 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/21 18:23:10 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	switch_a(t_env *piles)
{
	t_pile	*temp;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	temp = piles->a;
	piles->a = piles->a->next;
	piles->a->prev = NULL;
	temp->next = piles->a->next;
	temp->prev = piles->a;
	if (piles->a->next)
		piles->a->next->prev = temp;
	piles->a->next = temp;
	new_op(piles, 9);
	return;
}

void	push_b(t_env *piles)
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

void	push_up_a(t_env *piles)
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
	new_op(piles, 3);
	return;
}

void	push_down_a(t_env *piles)
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
	new_op(piles, 6);
	return;
}
