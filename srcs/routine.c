/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 03:38:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "end.h"
#include "routine.h"
#include "utils.h"
#define HALF_TIME 500
static int	is_even(t_philo *philo);
static int	do_sleep(t_philo *philo);
static int	do_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_until_all_threads_created(philo))
		return (set_err_flag(philo->data), NULL);
	if (philo->arg->number_of_philosophers == 1)
		return (take_one_fork(philo), NULL);
	if (is_even(philo) || philo->data->err_flag)
		return (set_err_flag(philo->data), NULL);
	while (1)
	{
		if (philo->data->end_flag)
			break ;
		if (do_eat(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
		if (philo->data->end_flag)
			break ;
		if (do_sleep(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
		if (philo->data->end_flag)
			break ;
		if (do_think(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
	}
	return (NULL);
}

int	wait_until_all_threads_created(t_philo *philo)
{
	pthread_mutex_lock(philo->data->data_mutex);
	philo->data->created++;
	if (get_milliseconds_time(&philo->data->start_ms))
		return (pthread_mutex_unlock(philo->data->data_mutex), ERR);
	philo->data->now_ms = 0;
	pthread_mutex_unlock(philo->data->data_mutex);
	while (1)
	{
		if (philo->data->created == philo->arg->monitor_size)
			break ;
		if (safe_usleep(SHORT_TIME, philo->data))
			return (ERR);
	}
	return (SUCCESS);
}

static int	is_even(t_philo *philo)
{
	if ((philo->idx + 1) % 2 == 0)
	{
		if (do_think(philo))
			return (ERR);
		if (safe_usleep(philo->arg->time_to_eat * HALF_TIME, \
			philo->data))
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
	return (SUCCESS);
}
