NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -I incs -MMD -MP
LDLIBS := -lpthread
RM := rm -rf

SRCS := srcs/main.c srcs/do_philo/do_philo.c \
		srcs/do_philo/do_something.c \
		srcs/do_philo/sleep_until_all_threads_are_created.c \
		srcs/do_philo/take_a_fork.c srcs/end_philo/destroy_all_mutex.c \
		srcs/end_philo/end_philo.c srcs/end_philo/is_end.c \
		srcs/get_philo/get_philo.c srcs/get_philo/init_all_mutex.c \
		srcs/get_philo/init_philo.c srcs/is_arg_valid/is_arg_valid.c \
		srcs/utils/check.c srcs/utils/put_msg.c srcs/utils/time.c \
		srcs/utils/ft_func/ft_atoi.c srcs/utils/ft_func/ft_isdigit.c \
		srcs/utils/ft_func/ft_putstr_fd.c srcs/utils/ft_func/ft_strcmp.c \
		srcs/utils/ft_func/ft_strlen.c
OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $@

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

-include $(DEPS)