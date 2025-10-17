/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:13:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 22:36:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // free malloc
#include "end.h"
#include "msg.h"
#include "philo.h"
#include "routine.h"
#include "utils.h"
#include "checker.h"

static int	born_to_be_thread(t_philo *philo, t_arg *arg, \
	pthread_t *thread, t_monitor *monitor);
static int	monitor_thread(t_philo *philo, t_data *data, \
	pthread_t *thread, t_monitor *monitor);
static void	*routine_monitor(void *arg);

int	philosopher(t_arg *arg)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;
	t_monitor	*monitor;

	if (init_data(&data, arg))
		return (ERR);
	if (init_philo(&philo, &data, arg))
		return (free_data(&data), ERR);
	if (init_monitor(&monitor, philo, &data))
		return (free_data(&data), free_philo(philo), ERR);
	thread = ft_calloc(data.thread_size, sizeof(pthread_t));
	if (!thread)
		return (free_data(&data), free_philo(philo), free(monitor), ERR);
	if (born_to_be_thread(philo, arg, thread, monitor))
		return (free(thread), free_data(&data), \
		free_philo(philo), free(monitor), ERR);
	return (free(thread), free_philo(philo), free_data(&data), \
	free(monitor), SUCCESS);
}

static int	born_to_be_thread(t_philo *philo, t_arg *arg, \
	pthread_t *thread, t_monitor *monitor)
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
	if (monitor_thread(philo, philo->data, \
		thread + arg->number_of_philosophers, monitor))
		return (set_err_flag(philo->data), ERR);
	i = -1;
	while (++i < philo->data->thread_size)
		if (pthread_join(*(thread + i), NULL))
			return (msg_function_err(ERR_MSG_JOIN), ERR);
	if (is_err(philo->data))
		return (ERR);
	return (SUCCESS);
}

static int	monitor_thread(t_philo *philo, t_data *data, \
	pthread_t *thread, t_monitor *monitor)
{
	int			i;

	i = -1;
	while (++i < data->monitor_size)
	{
		if (pthread_create((thread + i), NULL, routine_monitor, monitor + i))
		{
			set_err_flag(data);
			while (-philo->arg->number_of_philosophers < i--)
				pthread_join(*(thread + i), NULL);
			return (msg_function_err(ERR_MSG_CREATE), ERR);
		}
	}
	return (SUCCESS);
}

static void	*routine_monitor(void *arg)
{
	int			i;
	t_monitor	*monitor;

	monitor = (t_monitor *)arg;
	if (wait_until_all_threads_created(monitor->data))
		return (set_err_flag(monitor->data), NULL);
	while (1)
	{
		i = -1;
		while (++i < monitor->num_player)
			if (check_if_end(monitor->player + i))
				return (NULL);
		if (is_end(monitor->data) || is_err(monitor->data) \
			|| safe_usleep(SHORT_TIME, monitor->data))
			return (NULL);
	}
	return (NULL);
}
