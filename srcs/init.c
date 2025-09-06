/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:05:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 03:38:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h> // malloc

static int	safe_init(pthread_mutex_t **mutex, size_t count);

int	init_arg(int argc, char **argv, t_arg *arg)
{
	memset(arg, 0, sizeof(t_arg));
	arg->number_of_philosophers = (int)ft_ato64(argv[1]);
	arg->time_to_die = (uint64_t)ft_ato64(argv[2]);
	arg->time_to_eat = (uint64_t)ft_ato64(argv[3]);
	arg->time_to_sleep = (uint64_t)ft_ato64(argv[4]);
	arg->number_of_times_each_philosopher_must_eat = NO_OPTION;
	if (argc == OPTION_ARGC)
		arg->number_of_times_each_philosopher_must_eat = (int)ft_ato64(argv[5]);
	arg->monitor_size = arg->number_of_philosophers / PER_PHILO_NUM + 1;
	return (SUCCESS);
}

int	init_data(t_data *data, t_arg *arg)
{
	memset(data, 0, sizeof(t_data));
	if (safe_init(&data->data_mutex, 1))
		return (ERR);
	if (safe_init(&data->printf_mutex, 1))
		return (free_data(data), ERR);
	if (safe_init(&data->fork_mutex, arg->number_of_philosophers))
		return (free_data(data), ERR);
	if (safe_init(&data->end_mutex, 1))
		return (free_data(data), ERR);
	if (safe_init(&data->err_mutex, 1))
		return (free_data(data), 1);
	return (SUCCESS);
}

// success 0 error -1
int	init_philo(t_philo **philo, t_data *data, t_arg *arg)
{
	int	i;

	*philo = ft_calloc(arg->number_of_philosophers, sizeof(t_philo));
	if (!*philo)
		return (msg_function_err(ERR_MSG_MALLOC), ERR);
	i = -1;
	while (++i < arg->number_of_philosophers)
	{
		memset((*philo + i), 0, sizeof(t_philo));
		(*philo + i)->idx = i;
		(*philo + i)->data = data;
		(*philo + i)->arg = arg;
		if (i % 2 == 1)
		{
			(*philo + i)->first_fork_id = i;
			(*philo + i)->second_fork_id = (i + 1) % arg->number_of_philosophers;
		}
		else
		{
			(*philo + i)->first_fork_id = (i + 1) % arg->number_of_philosophers;
			(*philo + i)->second_fork_id = i;
		}
	}
	return (SUCCESS);
}

int	init_monitor(t_monitor **monitor, t_philo *philo, t_arg *arg)
{
	int	i;

	*monitor = ft_calloc(arg->monitor_size, sizeof(t_monitor));
	if (!*monitor)
		return (msg_function_err(ERR_MSG_MALLOC), ERR);
	i = -1;
	while (++i < arg->monitor_size)
	{
		(*monitor + i)->idx = i;
		if (i != arg->monitor_size)
			(*monitor + i)->num_player = PER_PHILO_NUM;
		else
			(*monitor + i)->num_player \
				= arg->number_of_philosophers % PER_PHILO_NUM;
		(*monitor + i)->player = philo + PER_PHILO_NUM * i;
	}
	return (SUCCESS);
}

static int	safe_init(pthread_mutex_t **mutex, size_t count)
{
	size_t	i;

	*mutex = ft_calloc(count, sizeof(pthread_mutex_t));
	if (!*mutex)
		return (msg_function_err(ERR_MSG_MALLOC), ERR);
	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init((*mutex + i), NULL))
			return (msg_function_err(ERR_MSG_INIT), ERR);
	}
	return (SUCCESS);
}
