/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:40 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/18 06:32:51 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h> 
# include <stdio.h>

typedef struct s_pile
{	
	int				data;
	int				pos;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct s_cmd
{	
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_env
{
	struct s_pile	*a;
	struct s_pile	*b;
	struct s_cmd	*oprs;
}					t_env;

t_pile	*lst_new(t_pile *prev);
t_env	*pile_filler(char **args, int argc);
void	clear_piles(t_env *piles);
int		up_or_down(int min, int max, t_env *piles);
void	err_display (int value);

#endif
