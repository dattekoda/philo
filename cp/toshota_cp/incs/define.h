#ifndef DEFINE_H
# define DEFINE_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TAKING_A_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIED "died\n"

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BOLD "\x1b[1m"

# define BLACK_B "\x1b[40m"
# define RED_B "\x1b[41m"
# define GREEN_B "\x1b[42m"
# define YELLOW_B "\x1b[43m"
# define BLUE_B "\x1b[44m"
# define MAGENTA_B "\x1b[45m"
# define CYAN_B "\x1b[46m"

# define DEFAULT "\x1b[0m\x1b[39m\x1b[49m"

# define NO_MIN_NUM_OF_PHILO_MUST_EAT -1
# define INITIAL_VALUE 1
# define AVAILABLE 1
# define UNAVAILABLE 0
# define MAXIMUM 1000

typedef struct s_philo_common
{
	bool			death_flag;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				born_count;
	int				full_count;
	int				time_to_start_do_philo;
	bool			*fork;

	pthread_mutex_t	born_count_mutex;
	pthread_mutex_t	full_count_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_flag_mutex;
	pthread_mutex_t	time_to_start_do_philo_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_philo_common;

typedef struct s_philo
{
	pthread_mutex_t	last_time_to_eat_mutex;
	pthread_t		thread_id;
	int				philo_nb;
	suseconds_t		last_time_to_eat;
	int				count_to_eat;
	int				right_fork_id;
	int				left_fork_id;
	t_philo_common	*common;
}	t_philo;

#endif
