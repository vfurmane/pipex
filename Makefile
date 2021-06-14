# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:23:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/14 13:31:24 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS		= $(addprefix srcs/, main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
