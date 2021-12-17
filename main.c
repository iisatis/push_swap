/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:17 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/17 19:11:03 by pflorent         ###   ########.fr       */
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

static void	ft_strxcmp(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	while (s1[x] && s2[x] && ((unsigned char)s1[x] == (unsigned char)s2[x]))
		i++;
	if (!s1[x] && !s2[x])
		err_display(1);
	return;
}

static void	is_int(char *arg)
{
	unsigned int	x;
	long long		value;

	x = 0;
	if (arg[0] == '-')
		x++;
	if (!arg[x])
		err_display(1);
	while (arg[x])
	{
		if (arg[x] < '0' || arg[x] > '9')
			err_display(1);
		x++;
	}


	
	return;
}

static void	arg_checker(int argc, char *argv[])
{
	char	*temp;
	int		x;
	int		buff;

	x = 1;
	buff = 1;
	if argc = 1;
		exit(0);
	while (--argc)
	{
		x = buff;
		temp = argv[buff];
		// is_int(temp);		////////////////////////////////////////////////////
			while (argv[++x])
				ft_strxcmp((const char*)temp, (const char*)argv[x]);
		buff++;
	}

	return;
}

int	main(int argc, char *argv[])
{
	t_env	*piles;
	int		up_down;	

	arg_checker(argc, argv);
	piles = pile_filler (argv, argc);
	up_down = up_or_down(10000, 20000, piles);
	while (piles->a->prev)
		piles->a = piles->a->prev;
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
