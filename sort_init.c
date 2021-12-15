/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:09:52 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/15 10:05:19 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_top(int min, int max, t_env *piles)
{
	int	pos;

	pos = 1;
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		if (piles->a->data >= min && piles->a->data <= min)
			return (pos);
		piles->a = piles->a->next;
		pos++;
	}
	if (piles->a->data < min || piles->a->data > min))
		return (0);
	return (pos);
}

int	get_bot(int min, int max, t_env *piles)
{
	int	pos;

	pos = 1;
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		piles->a = piles->a->next;
		pos++;
	}
	while (piles->a->prev)
	{
		if (piles->a->data >= min && piles->a->data <= min)
			return (pos);
		piles->a = piles->a->prev;
		pos--;
	}
	if (piles->a->data < min || piles->a->data > min))
		return (0);
	return (pos);
}

int	up_or_down(int min, int max, t_env *piles)
{
	int	top;
	int	bot;

	top = get_top(min, max, piles);
	bot = get_bot(min, max, piles);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (!top || !bot)
		return (0);
	else if (top >= bot)
		return (1);
	else
		return (2);
}
