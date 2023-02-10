# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 15:08:42 by arecce            #+#    #+#              #
#    Updated: 2023/02/10 19:18:05 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -pthread

SRCS = main.c src/check.c src/time.c src/init.c \
		src/forks.c src/threads.c src/eat_sleep_think.c \
		src/routine.c src/utils.c


HEADER = philo.h

OBJS = $(SRCS:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
BLU = \033[1;34m
# YEL = \033[1;33m
# WHT = \033[1;37m
EOC = \033[1;0m


# %.o: %.c
# 	@$(CC) -I ${MLX} -c $< -o $@

${NAME}: $(OBJS)
		@echo "$(BLU)Compiling philo...$(EOC)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "$(GREEN)Philosophers build completed.$(EOC)"
		
all: ${NAME}


clean:
		@echo "$(RED)Removing .o files...$(EOC)"
		@rm -f $(OBJS)
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(RED)Removing the latest files...$(EOC)"
		@rm -f $(NAME)
		@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re