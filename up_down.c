/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:24:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/19 19:10:56 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	get_top(int min, int max, t_pile *pile)
{
	int	pos;

	pos = 1;
	while (pile->prev)
		pile = pile->prev;
	while (pile->next)
	{
		if (pile->pos >= min && pile->pos <= max)
			return (pos);
		pile = pile->next;
		pos++;
	}
	if (pile->pos < min || pile->pos > max)
		return (0);
	return (pos);
}

static int	get_bot(int min, int max, t_pile *pile)
{
	int	pos;

	pos = 1;
	while (pile->next)
		pile = pile->next;
	while (pile->prev)
	{
		if (pile->pos >= min && pile->pos <= max)
			return (pos);
		pile = pile->prev;
		pos++;
	}
	if (pile->pos < min || pile->pos > max)
		return (0);
	return (pos);
}

int	up_or_down(int min, int max, t_pile *pile)
{
	int	top;
	int	bot;

	top = get_top(min, max, pile);
	bot = get_bot(min, max, pile);
	printf("\n   from top = %d	     from bot = %d \n\n", top, bot);
	while (pile->prev)
		pile = pile->prev;
	if (!top || !bot)
		return (0);
	else if (top <= bot)
		return (top);
	else
		return (-bot);
}