/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:40 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/22 15:26:14 by pflorent         ###   ########.fr       */
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
	int				cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_env
{
	struct s_pile	*a;
	struct s_pile	*b;
	struct s_cmd	*ops;
}					t_env;

void	check_args(int argc, char *argv[]);
void	is_sorted(t_env *piles);
t_pile	*lst_new(t_pile *prev);
t_cmd	*lst_new2(t_cmd *prev);
void	new_op(t_env *piles, int value);
t_env	*pile_filler(char **args, int argc);
void	clear_piles(t_env *piles);
void	printer(char *str);
void	err_display(int value);
int		up_or_down(int min, int max, t_pile *pile);
void	sort_two(t_env *piles);
void	sort_small(t_env *piles, int argc);
void	sort_big(t_env *piles, int argc, int cut);
void	push_a(t_env *piles);
void	push_up_a(t_env *piles);
void	push_down_a(t_env *piles);
void	switch_a(t_env *piles);
void	push_b(t_env *piles);
void	push_up_b(t_env *piles);
void	push_down_b(t_env *piles);

#endif
