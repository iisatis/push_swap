# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 15:46:55 by pflorent          #+#    #+#              #
#    Updated: 2021/12/22 17:28:26 by pflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS_P	=./sources/

SRCS_F	= main.c\
		check_args.c\
		pile_maker.c\
		utils_create.c\
		utils_exit.c\
		sort_small.c\
		sort_big.c\
		up_down.c\
		ops.c\
		ops2.c


SRCS	= $(addprefix $(SRCS_P), $(SRCS_F))

OBJS	= $(SRCS:.c=.o)

HEAD	= -I includes/

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		$(NAME)

${NAME}:	$(SRCS)
			$(CC) $(CFLAGS) $(HEAD) $(SRCS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re