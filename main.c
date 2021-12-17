/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/17 15:29:20 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	test_printer(t_env *piles)
{
	while (piles->a->next)
	{
		printf("	%d	||	%d\n", piles->a->pos, piles->a->data);
		piles->a = piles->a->next;
	}
}

int	main(int argc, char *argv[])
{
	t_env		*piles;

	piles = pile_filler (argv, argc);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	test_printer(piles);
	clear_piles (piles);
	return (0);
}
