/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:40:12 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/29 14:45:54 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_sorted(t_env *piles)
{
	int	buff;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	buff = piles->a->pos;
	while (piles->a->next)
	{
		piles->a = piles->a->next;
		if (buff > piles->a->pos)
			return ;
		buff = piles->a->pos;
	}
	clear_piles (piles);
	exit(0);
}

void	check_double(t_env *piles)
{
	int	buff;

	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		buff = piles->a->data;
		while (piles->a->next)
		{
			piles->a = piles->a->next;
			if (piles->a->data == buff)
			{
				clear_piles(piles);
				err_display(1);
			}
		}
		while (piles->a->prev->data != buff)
			piles->a = piles->a->prev;
	}
}

static void	is_int(char *arg)
{
	long long	n;
	int			np;
	int			x;

	x = 0;
	n = 0;
	np = 1;
	if (arg[x] == '-' || arg[x] == '+')
	{
		if (arg[x] == '-')
			np *= -1;
		x++;
	}
	while (arg[x] >= '0' && arg[x] <= '9')
	{
		n *= 10;
		n += (arg[x] - '0');
		x++;
	}
	n *= np;
	if (n < -2147483648 || n > 2147483647)
		err_display(1);
}

static void	is_num(char *arg)
{
	unsigned int	x;

	x = 0;
	if (arg[0] == '-' || arg[0] == '+')
		x++;
	if (!arg[x])
		err_display(1);
	while (arg[x])
	{
		if (arg[x] < '0' || arg[x] > '9')
			err_display(1);
		x++;
	}
	is_int(arg);
}

void	check_args(char **argv, int argc)
{
	char	*temp;
	int		x;

	x = 0;
	if (argc < 1)
		exit(0);
	else if (argc == 1)
	{
		temp = argv[0];
		is_num(temp);
	}
	else
	{
		while (argv[x])
		{
			temp = argv[x];
			is_num(temp);
			x++;
		}
	}
}
