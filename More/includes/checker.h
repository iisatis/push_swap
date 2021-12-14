
#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_pile
{
	struct s_pile	*next;
	int				data;
}					t_pile;

typedef struct		s_begin
{
	struct s_pile	*ba;
	struct s_pile	*bb;
}					t_begin;

t_pile				*ft_pilenew(int n);
t_pile				*ft_swap_pile(t_pile **bi);
t_pile				*ft_push_pile(t_pile **bf, t_pile **bi);
t_pile				*ft_rotate_pile(t_pile **bi);
t_pile				*ft_reverse_rotate_pile(t_pile **bi);
t_begin				*ft_init_begin(void);
void				ft_lstdel2(t_pile **begin);
void				ft_check_pile(t_pile **bi, t_pile **bb);
t_pile				*ft_build_pile(int argc, char **argv);
t_pile				*ft_build_pile_str(char *argv);
void				ft_check_doublon(char **argv, int i, int n);
void				ft_check_doublon_str(int *tab, int i, int n);
void				ft_rr(t_pile **elem);
void				ft_move(char *str, t_begin *begin);
void				ft_move2(char *str, t_begin *begin);
void				ft_print_list(t_pile **begin);

#endif
