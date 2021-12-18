/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:34:02 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 07:59:16 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_cmd	*sort_big (t_env *piles, int argc)
{
	long 	pos;
	long	stack;
	t_cmd	ops;

	stack = 1;
	ops = /* TO INIT */;
	while (argc > 0)
	{
		pos = up_or_down(stack, stack + 20, piles);





	}
	while (ops->prev)
		ops = ops->prev;
	return (ops);
}
