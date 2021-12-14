
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	struct s_pile	*inst;
}					t_begin;

t_pile				*ft_pilenew(int n);
t_begin				*ft_init_begin(void);
void				ft_lstdel2(t_pile **begin);
t_pile				*ft_swap_pile(t_pile **bi);
t_pile				*ft_push_pile(t_pile **bf, t_pile **bi);
t_pile				*ft_rotate_pile(t_pile **bi);
t_pile				*ft_reverse_rotate_pile(t_pile **bi);
int					ft_check(t_pile **bi, t_pile **bb);
int					ft_algo(t_begin *begin);
void				ft_check_doublon_str(int *tab, int i, int n);
t_pile				*ft_build_pile(int argc, char **argv);
t_pile				*ft_build_pile_str(char *argv);
void				ft_print_list(t_pile **begin);
void				ft_rr(t_pile **bi);
int					ft_find_len(t_pile **bi);
void				ft_work_a(t_begin *begin, int len);
void				ft_work_b(t_begin *begin, int len);
int					ft_is_sort(t_pile **begin, int pile);
void				ft_sort_tab(int *tab, int len);
int					ft_median(t_pile **begin, int pile, int n);
int					ft_compare_with_median(t_begin *begin, int n, \
					int median, int pile);
void				ft_sort_2_elem(t_begin *begin);
void				ft_sort_3_elem(t_begin *begin);
void				ft_sort_min_a(t_begin *begin);
void				ft_sort_min_b(t_begin *begin);
void				ft_instruction(t_pile **init, int n);

#endif
