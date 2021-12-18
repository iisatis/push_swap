/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 07:44:17 by pflorent         ###   ########.fr       */
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
	printf("	%d	||	%d\n", piles->a->pos, piles->a->data);
}

int	main(int argc, char *argv[])
{
	t_env	*piles;
	int		up_down;	

	arg_checker(argc, argv);
	piles = pile_filler (argv, argc);
	up_down = up_or_down(1, 20, piles);
	while (piles->a->prev)
		piles->a = piles->a->prev;

	if (argc < /* IDK YET */)
		piles->ops = sort_small(piles);
	if (argc > /* IDK YET */)
		piles->ops = sort_big(piles);

	test_printer(piles);
	if (up_down > 0)
		printf("\n\n	first is up");
	else if (up_down < 0)
		printf("\n\n	first is down");
	else if (up_down == 0)
		printf("\n\n	none found");
	clear_piles (piles);
	return (0);
}
