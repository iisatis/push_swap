/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:48 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/17 15:36:07 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_atoi(const char *str)
{
	long	n;
	int		np;

	n = 0;
	np = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
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

void	clear_piles(t_env *piles)
{
	t_pile	*temp;

	free(piles->b);
	free(piles->opr);
	while (piles->a->prev)
		piles->a = piles->a->prev;
	while (piles->a->next)
	{
		temp = piles->a->next;
		free(piles->a);
		piles->a = temp;
	}
	free(piles->a);
	free(piles);
}

static void	pos_parser(t_env *piles, int len)
{
	int	buff;

	while (len > 0)
	{
		buff = -2147483648;
		while (piles->a->next)
		{
			if (piles->a->data > buff && !piles->a->pos)
				buff = piles->a->data;
			piles->a = piles->a->next;
		}
		while (piles->a->prev)
		{
			if (piles->a->data == buff)
				piles->a->pos = len - 1;
			piles->a = piles->a->prev;
		}
		if (piles->a->data == buff)
			piles->a->pos = len - 1;
		len--;
	}
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

t_env	*pile_filler(char **args, int argc)
{
	t_env	*piles;
	int		x;

	piles = malloc(sizeof(t_env));
	if (!piles)
		return (NULL);
	piles->b = lst_new(NULL);
	piles->opr = lst_new(NULL);
	piles->a = lst_new(NULL);
	x = 0;
	while (x < argc - 1)
	{
		piles->a->data = ft_atoi(args[x + 1]);
		if (!piles->a->next)
			piles->a->next = lst_new(piles->a);
		piles->a = piles->a->next;
		x++;
	}
	while (piles->a->prev)
		piles->a = piles->a->prev;
	pos_parser(piles, argc);
	return (piles);
}
