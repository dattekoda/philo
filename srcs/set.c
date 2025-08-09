/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:49:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 16:48:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static int	set_arg(int argc, char **argv, t_data *data);

// set data from arg and set mutex
int	set_data(int argc, char **argv, t_data *data)
{
	int	i;

	if (set_arg(argc, argv, data))
		return (ERR);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->fork_mutex)
		return (ft_putendl_err("malloc"), ERR);
	i = -1;
	while (++i < data->num_philo)
		if (pthread_mutex_init(&data->fork_mutex[i], NULL))
			return (free_data(data), ft_putendl_err("init"), ERR);
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (free_data(data), ft_putendl_err("init"), ERR);
	return (SUCCESS);
}

static int	set_arg(int argc, char **argv, t_data *data)
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
