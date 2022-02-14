# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 13:57:50 by jkasongo          #+#    #+#              #
#    Updated: 2021/11/15 16:12:49 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

#source
SRCS =	main.c utils.c parse_args.c routine.c sync_code.c philo_init.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) est construit

clean :
	@rm -rf $(OBJS)
	@echo cleaning

fclean : clean
	@rm -rf $(NAME)
	@echo "full clean"

re : fclean all

launch:all
	./philo
