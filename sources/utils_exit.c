/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:27:21 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/23 16:03:59 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clear_ops(t_env *piles)
{
	t_cmd	*temp;

	while (piles->ops->next)
	{
		temp = piles->ops->next;
		free(piles->ops);
		piles->ops = temp;
	}
	free(piles->ops);
}

static void	clear_a(t_env *piles)
{
	t_pile	*temp;

	while (piles->a->next)
	{
		temp = piles->a->next;
		free(piles->a);
		piles->a = temp;
	}
	free(piles->a);
}

void	clear_args(char **to_free)
{
	int	x;

	x = 0;
	while (to_free[x])
	{
		free(to_free[x]);
		x++;
	}
	free(to_free);
}

void	clear_piles(t_env *piles)
{
	free(piles->b);
	if (piles->ops)
	{
		while (piles->ops->prev)
			piles->ops = piles->ops->prev;
		clear_ops(piles);
	}
	while (piles->a->prev)
		piles->a = piles->a->prev;
	clear_a(piles);
	free(piles);
}

void	err_display(int value)
{
	if (value == 1)
		printer("Error\n");
	exit(1);
}
