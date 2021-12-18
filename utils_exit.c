/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:27:21 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 07:29:17 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	clear_one_pile(t_pile *pile)
{
	t_pile	*prev;
	t_pile	*next;

	next = pile->next;
	prev = pile->prev;
	if (next)
		pile->next->prev = prev;
	if (prev)
		pile->prev->next = next;
	free(pile);
	if (prev)
		pile = prev;
	else
		pile = next;
}

void	clear_piles(t_env *piles)
{
	t_pile	*temp;

	free(piles->b);
	if (piles->opr);
		free(piles->opr);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		temp = piles->a->next;
		free(piles->a);
		piles->a = temp;
	}
	free(piles->a);
	free(piles);
}


void	err_display (int value)
{
	if (value == 1)
		printer("Error\n");
	exit(1);
}