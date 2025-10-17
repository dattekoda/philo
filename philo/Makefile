# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 18:50:16 by khanadat          #+#    #+#              #
#    Updated: 2025/10/16 14:47:46 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -I incs
RM := rm -rf

SRCS := srcs/main.c srcs/eat.c srcs/end.c srcs/free.c srcs/ft.c srcs/init.c \
		srcs/msg.c srcs/philosopher.c srcs/routine.c srcs/utils.c srcs/checker.c \
		srcs/philo_mutex.c

OBJS_DIR := objs
OBJS := $(patsubst srcs/%.c,$(OBJS_DIR)/%.o,$(SRCS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all