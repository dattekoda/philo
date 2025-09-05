/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 06:34:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"
#include "utils.h"
#define HALF_TIME 500

static int	wait_until_all_threads_created(t_philo *philo);
static int	is_odd(t_philo *philo);
static int	do_sleep(t_philo *philo);
static int	do_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_until_all_threads_created(philo))
		return (set_err_flag(philo->data), NULL);
	if (is_odd(philo) || philo->data->err_flag)
		return (set_err_flag(philo->data), NULL);
	while (1)
	{
		if (check_if_end(philo))
			break ;
		if (do_eat(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
		if (check_if_end(philo))
			break ;
		if (do_sleep(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
		if (check_if_end(philo))
			break ;
		if (do_think(philo) || philo->data->err_flag)
			return (set_err_flag(philo->data), NULL);
	}
	return (NULL);
}

static int	wait_until_all_threads_created(t_philo *philo)
{
	if (pthread_mutex_lock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_LOCK),  ERR);
	philo->data->created++;
	if (get_milliseconds_time(&philo->data->start_ms))
		return (pthread_mutex_unlock(philo->data->data_mutex), ERR);
	philo->data->now_ms = 0;
	if (pthread_mutex_unlock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_UNLOCK), ERR);
	while (1)
	{
		if (philo->data->created == philo->arg->number_of_philosophers)
			break ;
		if (philo->data->err_flag)
			return (ERR);
		if (safe_usleep(100))
			return (ERR);
	}
	return (SUCCESS);
}

static int	is_odd(t_philo *philo)
{
	if (philo->idx % 2 == 0)
	{
		if (safe_usleep(philo->arg->time_to_eat * HALF_TIME))
			return (ERR);
	}
	return (SUCCESS);
}

static int	do_sleep(t_philo *philo)
{
	if (safe_printf(philo, MSG_SLEEP))
		return (ERR);
	if (safe_usleep(philo->arg->time_to_sleep * MS_TO_US))
		return (ERR);
	if (pthread_mutex_lock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_LOCK), ERR);
	if (update_time_since_start(philo, &philo->data->now_ms))
		return (pthread_mutex_unlock(philo->data->data_mutex), ERR);
	if (pthread_mutex_unlock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_UNLOCK), ERR);
	if (update_dead_flag(philo))
		return (ERR);
	return (SUCCESS);
}

static int	do_think(t_philo *philo)
{
	if (safe_printf(philo, MSG_SLEEP))
		return (ERR);
	if (update_dead_flag(philo))
		return (ERR);
	return (SUCCESS);
}
