/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 07:27:40 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 07:29:17 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	printer2(char c)
{
	write(1, &c, 1);
	return;
}

void	printer (char *str)
{
	int	count;

	count = 0;
	while (str[count])
		printer2(str[count++]);
	return;
}
