# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:23:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/15 22:55:18 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS		= $(addprefix srcs/, init.c main.c put.c \
			  $(addprefix utils/, ft_free_array.c ft_getenv.c ft_memcpy.c ft_split.c ft_strccmp.c ft_strcdup.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strlen.c))
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -ggdb
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:		CFLAGS+= -fsanitize=address
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

nosanitize:	$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus nosanitize clean fclean re
