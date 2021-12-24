/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:55:01 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/24 16:45:17 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_env *piles)
{
	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (piles->a->pos > piles->a->next->pos)
		switch_a(piles);
}

void	sort_three(t_env *piles)
{
	int	f;
	int	s;
	int	t;

	f = piles->a->pos;
	s = piles->a->next->pos;
	t = piles->a->next->next->pos;
	if (f > s && s < t && t > f)
		switch_a(piles);
	else if (f > s && s > t && t < f)
		switch_a(piles);
	else if (f < s && s > t && t > f)
		switch_a(piles);
}
