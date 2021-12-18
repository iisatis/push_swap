/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:09:52 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 07:25:20 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	is_sorted(t_env *piles)
{
	int	buff;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	buff = piles->a->pos;
	while (piles->a->next)
	{
		piles->a = piles->a->next;
		if (buff > piles->a->pos)
			return;
		buff = piles->a->pos;
	}
	clear_piles (piles);
	exit(0);
}

t_cmd	*start_sort (t_env *piles, int argc)
{
	int		pos;
	t_cmd	ops;
	long	sort;

	is_sorted(piles);
	if (argc < /* IDK YET */)
		// sort_small(piles);
	if (argc > /* IDK YET */)
		// sort_big(piles);

}