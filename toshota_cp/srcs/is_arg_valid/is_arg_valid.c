#include "philo_func.h"

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static bool	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (is_sign(str[i]))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static void	put_argc_error(void)
{
	ft_putstr_fd("argc is 5 or 6 as follows:\n" \
		BOLD"./philo "GREEN"number_of_philosophers " \
		RED"time_to_die "MAGENTA"time_to_eat " \
		CYAN"time_to_sleep "
		BLUE"number_of_times_each_philosopher_must_eat\n" \
		DEFAULT \
		, STDERR_FILENO);
}

static void	put_argv_error(void)
{
	ft_putstr_fd("argv is as follows:\n" \
		BOLD"./philo "GREEN"number_of_philosophers " \
		RED"time_to_die "MAGENTA"time_to_eat " \
		CYAN"time_to_sleep "
		BLUE"number_of_times_each_philosopher_must_eat\n" \
		DEFAULT \
		, STDERR_FILENO);
}

bool	is_arg_valid(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (put_argc_error(), false);
	i = 1;
	while (argv[i])
	{
		if (is_str_digit(argv[i]) == false || ft_atoi(argv[i]) < 1)
			return (put_argv_error(), false);
		i++;
	}
	if (ft_atoi(argv[1]) > MAXIMUM)
		return (put_argc_error(), false);
	return (true);
}
