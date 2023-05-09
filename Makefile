# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 11:08:49 by emmagrevess       #+#    #+#              #
#    Updated: 2023/05/09 15:43:50 by egrevess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c\
		libft/atoi.c\
		thread/routine.c\
		utils/print.c\
		utils/check.c\
		utils/get_time.c\
		utils/finish.c\

OBJECT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECT)

		$(CC) $(CFLAGS) -o $(NAME) -fsanitize=thread $(OBJECT) 

.c.o:
		$(CC) $(CFLAGS) -fsanitize=thread -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJECT)

fclean: clean
		rm -f $(NAME)

re: 	fclean $(NAME)

.PHONY: all clean fclean re