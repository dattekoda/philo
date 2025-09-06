/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:13:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 05:46:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "end.h"
#include <stdlib.h> // free malloc

static int	born_to_be_thread(t_philo *philo, t_arg *arg, pthread_t *thread);
static void	monitor_philos(t_philo *philo, t_arg *arg, pthread_t * therad);

int	philosopher(t_arg *arg)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;

	if (init_data(&data, arg))
		return (ERR);
	if (init_philo(&philo, &data, arg))
		return (free_data(&data), ERR);
	thread = malloc(sizeof(pthread_t) \
		* (arg->number_of_philosophers + arg->monitor_size));
	if (!thread)
		return (free_data(&data), free(philo), ERR);
	if (born_to_be_thread(philo, arg, thread))
		return (free(thread), free_data(&data), free(philo), ERR);
	return (free(thread), free(philo), free_data(&data), SUCCESS);
}

static int	born_to_be_thread(t_philo *philo, t_arg *arg, pthread_t *thread)
{
	int		i;

	i = -1;
	while (++i < arg->number_of_philosophers)
	{
		if (pthread_create((thread + i), NULL, routine, philo + i))
		{
			set_err_flag(philo->data);
			while (0 < i--)
				pthread_join(*(thread + i), NULL);
			return (msg_function_err(ERR_MSG_CREATE), ERR);
		}
	}
	if (monitor_philos(philo, arg, thread + arg->number_of_philosophers))
		return (set_err_flag(philo->data->err_flag), ERR);
	i = -1;
	while (++i < arg->number_of_philosophers + arg->monitor_size)
	{
		if (pthread_join(*(thread + i), NULL))
			return (msg_function_err(ERR_MSG_JOIN), ERR);
	}
	if (philo->data->err_flag)
		return (ERR);
	return (SUCCESS);
}

static int	monitor_philos(t_philo *philo, t_arg *arg, pthread_t *thread)
{
	int			i;
	t_monitor	*monitor;

	if (init_monitor(&monitor, philo, arg))
		return (ERR);
	i = -1;
	while (++i < philo->data->monitor_size)
	{
		if (pthread_create((thread + i), NULL, routine_monitor, monitor + i))
		{
			set_err_flag(philo->data);
			while (0 < i--)
				pthread_join(*(thread + i), NULL);
			return (msg_function_err(ERR_MSG_CREATE), ERR);
		}
	}
}

void	*routine_monitor(void *arg)
{
	int			i;
	t_monitor	*monitor;

	monitor = (t_monitor *)monitor;
	if (wait_until_all_threads_created(monitor->data))
		return (set_err_flag(monitor->data), NULL);
	while (1)
	{
		i = -1;
		while (++i < monitor->num_player)
			if (check_if_end(monitor->player + i))
				return (NULL);
		if (monitor->data->err_flag \
			|| safe_usleep(SHORT_TIME, monitor->data))
			return (NULL);
	}
}