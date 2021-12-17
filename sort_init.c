/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:09:52 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/17 17:39:00 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	get_top(int min, int max, t_env *piles)
{
	int	pos;

	pos = 1;
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		if (piles->a->pos >= min && piles->a->pos <= max)
			return (pos);
		piles->a = piles->a->next;
		pos++;
	}
	if (piles->a->pos < min || piles->a->pos > max)
		return (0);
	return (pos);
}

static int	get_bot(int min, int max, t_env *piles)
{
	int	pos;

	pos = 1;
	while (piles->a->next)
		piles->a = piles->a->next;
	while (piles->a->prev)
	{
		if (piles->a->pos >= min && piles->a->pos <= max)
			return (pos);
		piles->a = piles->a->prev;
		pos++;
	}
	if (piles->a->pos < min || piles->a->pos > max)
		return (0);
	return (pos);
}

int	up_or_down(int min, int max, t_env *piles)
{
	int	top;
	int	bot;

	top = get_top(min, max, piles);
	bot = get_bot(min, max, piles);
	printf("\n	from top = %d	from bot = %d \n\n", top, bot);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (!top || !bot)
		return (0);
	else if (top <= bot)
		return (1);
	else
		return (2);
}
