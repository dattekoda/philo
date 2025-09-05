/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:54:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 15:51:02 by khanadat         ###   ########.fr       */
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

# define DEFAULT_ARGC 5
# define OPTION_ARGC 6
# define NO_OPTION -1

# define ERR_MSG_USAGE "Usage: "
# define ERR_MSG_INVALID "Invalid number of arguments.\n"
# define ERR_MSG_ARGUMENTS " number_of_philosophers" \
" time_to_die" \
" time_to_eat" \
" time_to_sleep" \
" [number_of_times_each_philosopher_must_eat]\n"
# define ERR_MSG_FORMAT "Invalid format of arguments.\n" \
"number_of_philosophers > 0\n" \
"time_to_die > 1\n" \
"time_to_eat > 1\n" \
"time_to_sleep > 1\n" \
"[number_of_times_each_philosopher_must_eat] > 0\n"
# define ERR_MSG_INIT "pthread_mutex_init"
# define ERR_MSG_MALLOC "malloc"
# define ERR_MSG_LOCK "pthread_mutex_lock"
# define ERR_MSG_UNLOCK "pthread_mutex_unlock"
# define ERR_MSG_DESTROY "pthread_mutex_destroy"
# define ERR_MSG_PRINTF "printf"
# define ERR_MSG_GETTIMEOFDAY "gettimeofday"
# define MSG_DIE "died"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_FORK " has taken a fork"

typedef struct s_arg
{
	int			number_of_philosophers;
	int64_t		time_to_die;
	int64_t		time_to_eat;
	int64_t		time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_arg;

typedef struct s_data
{
	int				created;
	// check if all philos are over number_of_times_each_philosopher_must_eat
	int				ended_nums;
	int64_t			start_ms;
	int64_t			now_ms;
	bool			someone_dead;
	pthread_mutex_t	*data_mutex;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_data;

typedef struct s_philo
{
	int				idx;
	bool			dead;
	int				eat_count;
	bool			over_mustcount;
	int64_t			last_time_to_eat;
	t_data			*data;
	t_arg			*arg;
}	t_philo;

#endif