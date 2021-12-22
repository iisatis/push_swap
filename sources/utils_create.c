/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:59:36 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/22 15:10:55 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_cmd	*lst_new2(t_cmd *prev)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->next = NULL;
	new->cmd = 0;
	return (new);
}

t_pile	*lst_new(t_pile *prev)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->next = NULL;
	new->data = 0;
	new->pos = 0;
	return (new);
}

void	new_op(t_env *piles, int value)
{
	if (!piles->ops)
		piles->ops = lst_new2(NULL);
	else
	{
		while (piles->ops->next)
			piles->ops = piles->ops->next;
		piles->ops->next = lst_new2(piles->ops);
		piles->ops = piles->ops->next;
	}
	piles->ops->cmd = value;
}
