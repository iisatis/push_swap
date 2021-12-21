/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/21 18:38:42 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	print_op(t_env *piles)
{
	t_cmd	*temp;

	while (piles->ops->prev)
		piles->ops = piles->ops->prev;
	temp = piles->ops;
	while (piles->ops)
	{
		if (piles->ops->cmd == 1)
			printf("pa\n");
		else if (piles->ops->cmd == 2)
			printf("pb\n");
		else if (piles->ops->cmd == 3)
			printf("ra\n");
		else if (piles->ops->cmd == 4)
			printf("rb\n");
		else if (piles->ops->cmd == 6)
			printf("rra\n");
		else if (piles->ops->cmd == 7)
			printf("rrb\n");
		else if (piles->ops->cmd == 9)
			printf("sa\n");
		piles->ops = piles->ops->next;
	}
	piles->ops = temp;
	return;
}

int	main(int argc, char *argv[])
{
	t_env	*piles;

	check_args(argc, argv);
	piles = pile_filler (argv, argc);
	is_sorted(piles);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (argc > 120)
		sort_big(piles, argc - 1, 12);
	else if (argc > 7)
		sort_big(piles, argc - 1, 4);	
	else if (argc > 3)
		sort_small(piles, (argc - 1));
	else if (argc == 3)
		sort_two(piles);
	print_op(piles);
	clear_piles (piles);
	return (0);
}
