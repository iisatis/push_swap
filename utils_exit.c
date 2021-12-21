/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:27:21 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/21 15:30:01 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	clear_piles(t_env *piles)
{
	t_pile	*temp;
	t_cmd	*temp2;

	free(piles->b);
	if (piles->ops)
	{
		while (piles->ops->prev)
			piles->ops = piles->ops->prev;	
		while (piles->ops->next)
		{
			temp2 = piles->ops->next;
			free(piles->ops);
			piles->ops = temp2;
		}
		free(piles->ops);
	}
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