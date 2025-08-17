/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:38:46 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 18:02:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERR 1
# define SUCCESS 0
# define NUM_NORMAL_ARG 5
# define NUM_OPTIONAL_ARG 6

# define STATE_FORK "has taken a fork"
# define STATE_EAT "is eating"
# define STATE_SLEEP "is sleeping"
# define STATE_THINK "is thinking"
# define STATE_DIE "died"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h> //mutex
# include <sys/time.h>

typedef struct s_data
{
	bool			optional;
	int				num_times_eat; // 5
	int				num_philo; // 1
	long			time_die; // 2
	long			time_eat; // 3
	long			time_sleep; // 4
	long			start_ms;
	pthread_mutex_t	
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex; // malloc
}	t_data;

typedef struct s_philo
{
	int				idx;
	int				state; //0:none 1:die 2:eat 3:sleep
	long			last_eat;
	long			now_ms;
	t_data			*data;
}	t_philo;

// free.c
void	free_data(t_data *data);

// philo.c
int		philosopher(t_data *data);

// routine.c
void	*routine(void *arg);

// set.c
int		set_data(int argc, char **argv, t_data *data);
int		set_philos(t_data *data, t_philo **philos);

// utils.c
long	get_time_in_ms(void);
void	ft_putendl_err(char *str);
int		simple_atoi(char *str);
int		print_state(t_philo *ph, int idx, char *state);
void	high_prec_msleep(long ms);

#endif