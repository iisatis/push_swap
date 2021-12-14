
NAME_C = checker
NAME_P = push_swap


_SRCS_C = main.c \
		ft_list.c \
		ft_op_pile.c \
		ft_build_pile_str.c \
		ft_aux.c \
		ft_move.c

_SRCS_P = ft_algo.c \
		ft_list.c \
		ft_op_pile.c \
		main.c \
		ft_build_pile.c \
		ft_build_pile_str.c \
		ft_tool_func.c \
		ft_short_sort.c \
		ft_work_b.c \
		ft_work_a.c

SRCS_C_DIR = check
SRCS_P_DIR = push
SRCS_C = $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_C = $(SRCS_C:.c=.o)
SRCO_P = $(SRCS_P:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(NAME_C) : $(SRCO_C)
	make -C libft
	gcc -o $(NAME_C) -Llibft -lft $(SRCO_C)

$(NAME_P) : $(SRCO_P)
	make -C libft
	gcc -o $(NAME_P) -Llibft -lft $(SRCO_P)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_C)
	/bin/rm -f $(SRCO_P)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_P)
	/bin/rm -f libft/libft.a

re :
	make fclean
	make
