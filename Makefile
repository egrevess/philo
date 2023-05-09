# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 11:08:49 by emmagrevess       #+#    #+#              #
#    Updated: 2023/05/09 12:08:54 by emmagrevess      ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -g

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