/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:54:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/11 20:55:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>

# define ERR -1
# define SUCCESS 0
# define FAILURE 1

# define END 1
# define NOT_END 0

# define DEFAULT_ARGC 5
# define OPTION_ARGC 6
# define NO_OPTION -1
# define MS_TO_US 1000
# define SHORT_TIME 100
# define PER_PHILO_NUM 5 // monitors check this number of philo in each thread.

# define ERR_MSG_USAGE "Usage: "
# define ERR_MSG_INVALID "Invalid number of arguments.\n"
# define ERR_MSG_INIT "pthread_mutex_init"
# define ERR_MSG_MALLOC "malloc"
# define ERR_MSG_DESTROY "pthread_mutex_destroy"
# define ERR_MSG_PRINTF "printf"
# define ERR_MSG_GETTIMEOFDAY "gettimeofday"
# define ERR_MSG_USLEEP "usleep"
# define ERR_MSG_JOIN "pthread_join"
# define ERR_MSG_CREATE "pthread_create"
# define MSG_DIE "died"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_FORK "has taken a fork"

typedef struct s_arg
{
	int			number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_arg;

// check if all philos are over
// number_of_times_each_philosopher_must_eat
typedef struct s_data
{
	bool			end_flag; // over must_eat or dead
	bool			err_flag;
	int				created;
	int				ended_nums;
	int				thread_size;
	int				monitor_size;
	uint64_t		start_ms;
	uint64_t		now_ms;
	pthread_mutex_t	*data_mutex;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*end_mutex;
	pthread_mutex_t	*err_mutex;
	pthread_mutex_t	*now_ms_mutex;
}	t_data;

typedef struct s_philo
{
	bool			dead;
	bool			over_mustcount;
	int				idx;
	int				eat_count;
	int				first_fork_id;
	int				second_fork_id;
	int64_t			last_time_to_eat;
	t_data			*data;
	t_arg			*arg;
}	t_philo;

typedef struct s_monitor
{
	int				idx;
	int				num_player;
	t_philo			*player;
	t_data			*data;
}	t_monitor;

#endif