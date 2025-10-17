/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 22:37:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "end.h"
#include "msg.h"
#include "routine.h"
#include "utils.h"
#include "checker.h"
#define WAIT_TIME 600
#define FASTER_THAN_EVEN 900

static int	adjust_order(t_philo *philo);
static int	do_sleep(t_philo *philo);
static int	do_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_until_all_threads_created(philo->data))
		return (set_err_flag(philo->data), NULL);
	if (philo->arg->number_of_philosophers == 1)
		return (take_one_fork(philo), NULL);
	if (adjust_order(philo) || is_err(philo->data))
		return (set_err_flag(philo->data), NULL);
	while (1)
	{
		if (is_end(philo->data))
			break ;
		if (do_eat(philo) || is_err(philo->data))
			return (set_err_flag(philo->data), NULL);
		if (is_end(philo->data))
			break ;
		if (do_sleep(philo) || is_err(philo->data))
			return (set_err_flag(philo->data), NULL);
		if (is_end(philo->data))
			break ;
		if (do_think(philo) || is_err(philo->data))
			return (set_err_flag(philo->data), NULL);
	}
	return (NULL);
}

int	wait_until_all_threads_created(t_data *data)
{
	pthread_mutex_lock(data->data_mutex);
	data->created++;
	if (get_milliseconds_time(&data->start_ms))
		return (pthread_mutex_unlock(data->data_mutex), ERR);
	pthread_mutex_unlock(data->data_mutex);
	pthread_mutex_lock(data->now_ms_mutex);
	data->now_ms = 0;
	pthread_mutex_unlock(data->now_ms_mutex);
	while (1)
	{
		pthread_mutex_lock(data->data_mutex);
		if (data->created == data->thread_size)
			break ;
		pthread_mutex_unlock(data->data_mutex);
		if (safe_usleep(SHORT_TIME, data))
			return (ERR);
	}
	pthread_mutex_unlock(data->data_mutex);
	return (SUCCESS);
}

static int	adjust_order(t_philo *philo)
{
	if (philo->is_odd)
	{
		if (safe_printf(philo, MSG_THINK))
			return (ERR);
		if (safe_usleep(philo->arg->time_to_eat * WAIT_TIME, \
			philo->data))
			return (ERR);
	}
	if (philo->arg->is_odd \
	&& philo->idx + 1 == philo->arg->number_of_philosophers)
	{
		if (safe_usleep(philo->arg->time_to_eat * WAIT_TIME, philo->data))
			return (ERR);
	}
	return (SUCCESS);
}

static int	do_sleep(t_philo *philo)
{
	if (safe_printf(philo, MSG_SLEEP))
		return (ERR);
	if (safe_usleep(philo->arg->time_to_sleep * MS_TO_US, \
		philo->data))
		return (ERR);
	return (SUCCESS);
}

static int	do_think(t_philo *philo)
{
	if (safe_printf(philo, MSG_THINK))
		return (ERR);
	if (!philo->arg->is_odd)
		return (SUCCESS);
	if (!philo->is_odd)
	{
		if (safe_usleep(philo->arg->time_to_eat * MS_TO_US, philo->data))
			return (ERR);
	}
	else
	{
		if (safe_usleep(philo->arg->time_to_eat * FASTER_THAN_EVEN, \
			philo->data))
			return (ERR);
	}
	return (SUCCESS);
}
