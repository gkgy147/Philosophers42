# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:49:56 by grobert           #+#    #+#              #
#    Updated: 2023/05/25 10:27:21 by grobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccyan="\033[1;36m"
cgreen=$("\033[1;32m")
cred="\033[1;31m"
cend=$("\033[0m")

NAME	= philo

SRCS	= philo.c ft_actions.c utils.c utils1.c
OBJS	= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m➜\033[0m \033[1;32m Project compiled\033[0m"

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@echo "\033[1;32m➜\033[0m \033[1;31m Object files deleted\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[1;32m➜\033[0m \033[1;31m Project cleaned\033[0m"

clear:
	clear

re: clear fclean all
	@echo "\033[1;32m➜\033[0m \033[1;36m Project cleaned and recompiled\033[0m"

.PHONY: all clean fclean re
