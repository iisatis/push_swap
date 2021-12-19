/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:40 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/19 19:10:56 by pflorent         ###   ########.fr       */
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
void	clear_one_pile(t_pile *pile);
void	printer (char *str);
void	err_display (int value);
int		up_or_down(int min, int max, t_pile *pile);
t_cmd	*sort_small (t_env *piles, int argc);
t_cmd	*sort_big (t_env *piles, int argc);
void	push_back_a(t_env *piles, int size);

#endif


/*

1 pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.

2 pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.

3 ra : rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.

4 rb : rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.

5 rr : ra et rb en même temps.

6 rra : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.

7 rrb : reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.

8 rrr : rra et rrb en même temps.

9 sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.

10 sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.

11 ss : sa et sb en même temps.

*/