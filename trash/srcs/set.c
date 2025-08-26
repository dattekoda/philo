/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:49:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/19 10:37:34 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// set data from arg and set mutex
int	set_data(int argc, char **argv, t_data *data)
{
	data->num_times_eat = -1;
	data->optional = false;
	if (argc == NUM_OPTIONAL_ARG)
	{
		data->num_times_eat = simple_atoi(argv[--argc]);
		data->optional = true;
	}
	data->time_sleep = simple_atoi(argv[--argc]);
	data->time_eat = simple_atoi(argv[--argc]);
	data->time_die = simple_atoi(argv[--argc]);
	data->num_philo = simple_atoi(argv[--argc]);
	if (data->num_philo < 1 || data->time_sleep < 0
		|| data->time_eat < 0 || data->time_die < 0
		|| (data->optional && data->num_times_eat < 0))
		return (ft_putendl_err("Invalid format of arguments."), ERR);
	data->created_num = 0;
	if (data->optional)
	{
		data->list_eat_nums = ft_calloc(data->num_philo, sizeof(int));
		if (!data->list_eat_nums)
			return (ft_putendl_err("malloc"), ERR);
	}
	return (SUCCESS);
}

int	set_mutex(t_data *data, t_mutex *mutex)
{
	int	i;

	mutex->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!mutex->fork_mutex)
		return (ft_putendl_err("malloc"), ERR);
	i = -1;
	while (++i < data->num_philo)
		if (pthread_mutex_init(&mutex->fork_mutex[i], NULL))
			return (free_philo(data, mutex), ft_putendl_err(ERR_INIT), ERR);
	if (pthread_mutex_init(&mutex->print_mutex, NULL))
		return (free_philo(data, mutex), ft_putendl_err(ERR_INIT), ERR);
	if (pthread_mutex_init(&mutex->list_mutex, NULL))
		return (free_philo(data, mutex), ft_putendl_err(ERR_INIT), ERR);
	if (pthread_mutex_init(&mutex->created_num_mutex, NULL))
		return (free_philo(data, mutex), ft_putendl_err(ERR_INIT), ERR);
	if (pthread_mutex_init(&mutex->start_ms_mutex, NULL))
		return (free_philo(data, mutex), ft_putendl_err(ERR_INIT), ERR);
	return (SUCCESS);
}

// set t_philo
int	set_philos(t_data *data, t_mutex *mutex, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!(*philos))
		return (ft_putendl_err("malloc"), ERR);
	i = -1;
	while (++i < data->num_philo)
		(*philos)[i] = (t_philo){i, 0, 0, data, mutex};
	data->start_ms = get_time_in_ms();
	return (SUCCESS);
}
