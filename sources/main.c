/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/22 18:02:44 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	printer2(char c)
{
	write(1, &c, 1);
}

void	printer(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		printer2(str[count++]);
}

static void	print_op(t_env *piles)
{
	t_cmd	*temp;

	while (piles->ops->prev)
		piles->ops = piles->ops->prev;
	temp = piles->ops;
	while (piles->ops)
	{
		if (piles->ops->cmd == 1)
			printer("pa\n");
		else if (piles->ops->cmd == 2)
			printer("pb\n");
		else if (piles->ops->cmd == 3)
			printer("ra\n");
		else if (piles->ops->cmd == 4)
			printer("rb\n");
		else if (piles->ops->cmd == 6)
			printer("rra\n");
		else if (piles->ops->cmd == 7)
			printer("rrb\n");
		else if (piles->ops->cmd == 9)
			printer("sa\n");
		piles->ops = piles->ops->next;
	}
	piles->ops = temp;
}

static char	**arg_splitter(char **argv, int argc)
{
	char	**args;

	if (argc == 2
	return (args);
}

int	main(int argc, char **argv)
{
	t_env	*piles;
	char	**args;

	
	args = arg_splitter(++argv, argc);
	argc = // check argc now



	check_args(argc, args);
	piles = pile_filler (args, argc);
	is_sorted(piles);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (argc > 120)
		sort_big(piles, argc, 12);
	else if (argc > 6)
		sort_big(piles, argc, 4);
	else if (argc > 2)
		sort_small(piles, (argc));
	else if (argc == 2)
		sort_two(piles);
	print_op(piles);
	clear_piles (piles);
	return (0);
}
