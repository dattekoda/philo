/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:38:46 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 16:21:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERR -1
# define SUCCESS 0
# define FAILURE 1
# define END 2 // is_end
# define NUM_NORMAL_ARG 5
# define NUM_OPTIONAL_ARG 6

# define STATE_FORK "has taken a fork"
# define STATE_EAT "is eating"
# define STATE_SLEEP "is sleeping"
# define STATE_THINK "is thinking"
# define STATE_DIE "died"

# define ERR_INIT "pthread_mutex_init"
# define ERR_LOCK "pthread_mutex_lock"
# define ERR_UNLOCK "pthread_mutex_unlock"
# define ERR_PRINTF "printf"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h> //mutex
# include <sys/time.h>
# include <stdint.h> // SIZE_MAX
# include <string.h> // memset

typedef struct s_mutex
{
	pthread_mutex_t	list_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex; // malloc
}	t_mutex;

typedef struct s_data
{
	bool	optional;
	int		num_times_eat; // 5
	int		num_philo; // 1
	int		time_die; // 2
	int		time_eat; // 3
	int		time_sleep; // 4
	int		start_ms;
	int		*list_eat_nums; // malloc
}	t_data;

typedef struct s_philo
{
	int		idx;
	int		last_eat;
	int		now_ms;
	t_data	*data;
	t_mutex	*mutex;
}	t_philo;

// end.c
int	is_end(t_philo *ph);
int	is_dead(t_philo *ph);

// err.c
void	exit_philo(t_philo *philo, char *str);

// free.c
void	free_data(t_data *data);
void	free_philo(t_data *data, t_mutex *mutex);

// ft.c
void	ft_swap(int *a, int *b);
void	ft_putendl_err(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

// philo.c
int		philosopher(t_data *data, t_mutex *mutex);

// routine.c
void	*routine(void *arg);

// set.c
int		set_data(int argc, char **argv, t_data *data);
int		set_mutex(t_data *data, t_mutex *mutex);
int		set_philos(t_data *data, t_mutex *mutex, t_philo **philos);

// utils.c
int		get_time_in_ms(void);
int		simple_atoi(char *str);
int		print_state(t_philo *ph, char *state);
int		high_prec_usleep(int ms);

#endif