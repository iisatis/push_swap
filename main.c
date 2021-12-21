/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/21 18:06:38 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
static void	push_a(t_env *piles)
{
	t_pile	*temp;

	if (piles->a)
		while (piles->a->prev)
			piles->a = piles->a->prev;
	while (piles->b->prev)
		piles->b = piles->b->prev;
	temp = piles->b->next;
	piles->b->next = piles->a;
	if(piles->a)
		piles->a->prev = piles->b;
	piles->a = piles->b;
	piles->b = temp;
	if (piles->b)
		piles->b->prev = NULL;
	new_op(piles, 1);
	return;
}

static void	push_b(t_env *piles)
{
	t_pile	*temp;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	if (piles->b)
		while (piles->b->prev)
			piles->b = piles->b->prev;
	temp = piles->a->next;
	piles->a->next = piles->b;
	if(piles->b)
		piles->b->prev = piles->a;
	piles->b = piles->a;
	piles->a = temp;
	if (piles->a)
		piles->a->prev = NULL;
	new_op(piles, 2);
	return;
}

static void	test_printer2(t_env *piles)
{

	while (piles->b->next)
	{
		printf("	%d	||	%d\n", piles->b->pos, piles->b->data);
		piles->b = piles->b->next;
	}
	printf("	%d	||	%d\n", piles->b->pos, piles->b->data);
	while (piles->b->prev)
		piles->b = piles->b->prev;
}*/

static void	test_printer(t_env *piles)
{
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		printf("	%d	||	%d\n", piles->a->pos, piles->a->data);
		piles->a = piles->a->next;
	}
	printf("	%d	||	%d\n\n", piles->a->pos, piles->a->data);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	return;
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
	test_printer(piles);
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


	while (piles->a->prev)
		piles->a = piles->a->prev;
	test_printer(piles);
	print_op(piles);
	clear_piles (piles);
	return (0);
}


/*
IF DOES NOT WORK ANYMORE: RM VOID, PUT T_CMD!
*/