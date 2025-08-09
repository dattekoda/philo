/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:49:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/08 23:46:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// set data from argv
int	set_data(int argc, char **argv, t_data *data)
{
	int	i;

	data->num_times_eat = -1;
	data->optional = false;
	if (argc == NUM_OPTIONAL_ARG)
	{
		data->num_times_eat = (int) ft_atol(argv[--argc]);
		data->optional = true;
	}
	data->time_to_sleep = ft_atol(argv[--argc]);
	data->time_to_eat = ft_atol(argv[--argc]);
	data->time_to_die = ft_atol(argv[--argc]);
	data->num_philo = (int) ft_atol(argv[--argc]);
	if (data->num_philo < 1 || data->time_to_sleep < 0
		|| data->time_to_eat < 0 || data->time_to_die < 0
		|| (data->optional && data->num_times_eat < 0))
		return (ft_putendl_err("Invalid format of arguments."), ERR);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->fork)
		return (ft_putendl_err("malloc"), ERR);
	i = -1;
	while (++i < data->num_philo)
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (free_data(data), ft_putendl_err("init"), ERR);
	return (SUCCESS);
}

// set t_philo
int	set_philos(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!(*philos))
		return (ft_putendl_err("malloc"), ERR);
	i = -1;
	while (++i < data->num_philo)
		(*philos)[i] = (t_philo){i, 0, 0, 0, data};
	return (SUCCESS);
}
