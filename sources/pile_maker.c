/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:48 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/29 14:50:58 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_atoi(const char *str)
{
	long	n;
	int		np;

	n = 0;
	np = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			np *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += (*str - '0');
		str++;
	}
	n *= np;
	return (n);
}

static void	pos_parser(t_env *piles, int len)
{
	long	buff;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (len >= 0)
	{
		buff = -2147483649;
		while (piles->a->next)
		{
			if (piles->a->data > buff && !piles->a->pos)
				buff = piles->a->data;
			piles->a = piles->a->next;
		}
		if (piles->a->data > buff && !piles->a->pos)
			buff = piles->a->data;
		while (piles->a->prev)
		{
			if (piles->a->data == buff)
				piles->a->pos = len;
			piles->a = piles->a->prev;
		}
		if (piles->a->data == buff)
			piles->a->pos = len;
		len--;
	}
}

static int	arg_count(char **argv, int argc)
{
	int	count;

	count = 0;
	if (argc != 2)
		count = argc - 1;
	else
		while (argv[count])
			count++;
	return (count);
}

static char	**create_args(char **argv, int argc)
{
	char	**args;

	args = NULL;
	if (argc > 2)
		args = ft_dup_tab(argv, argc);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	return (args);
}

t_env	*pile_filler(char **argv, int argc)
{
	t_env	*piles;
	char	**args;
	int		x;

	args = create_args(argv, argc);
	argc = arg_count(args, argc);
	check_args(args, argc);
	piles = malloc(sizeof(t_env));
	if (!piles)
		return (NULL);
	piles->b = NULL;
	piles->ops = NULL;
	piles->a = lst_new(NULL);
	x = 0;
	piles->a->data = ft_atoi(args[x]);
	while (++x < argc)
	{
		piles->a->next = lst_new(piles->a);
		piles->a = piles->a->next;
		piles->a->data = ft_atoi(args[x]);
	}
	clear_args(args);
	pos_parser(piles, argc);
	return (piles);
}
