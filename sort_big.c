/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:34:02 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 08:07:36 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_cmd	*sort_big (t_env *piles, int argc)
{
	int 	pos;
	int		stack;
	t_cmd	ops;

	stack = 1;
	pos = 1;
	ops = /* TO INIT */;
	while (argc > 0)
	{
		while (pos && argc > 0)
		{
			pos = up_or_down(stack, stack + 20, piles);



		}
		stack += 20;
	}
	while (ops->prev)
		ops = ops->prev;
	return (ops);
}
