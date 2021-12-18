/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:38:57 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 06:05:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	printer2(char c)
{
	write(1, &c, 1);
	return;
}

static void	printer (char *str)
{
	int	count;

	count = 0;
	while (str[count])
		printer2(str[count++]);
	return;
}

void	err_display (int value)
{
	if (value == 1)
		printer("Error\n");
	exit(1);
}