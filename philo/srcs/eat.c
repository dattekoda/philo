/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:25:19 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 21:47:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "define.h"
#include "end.h"
#include "msg.h"
#include "utils.h"

static int	update_eat(t_philo *philo);
static int	take_forks(t_philo *philo);

int	do_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (ERR);
	if (update_eat(philo))
		return (pthread_mutex_unlock(philo->first_fork), \
		pthread_mutex_unlock(philo->second_fork), ERR);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
	return (SUCCESS);
}

static int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(philo->first_fork), ERR);
	pthread_mutex_lock(philo->second_fork);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(philo->first_fork), \
		pthread_mutex_unlock(philo->second_fork), ERR);
	return (SUCCESS);
}

static int	update_eat(t_philo *philo)
{
	int	must_eat;

	if (safe_printf(philo, MSG_EAT))
		return (ERR);
	update_ltte(philo, get_now_ms(philo->data));
	update_eat_count(philo);
	must_eat = philo->arg->number_of_times_each_philosopher_must_eat;
	if (must_eat != NO_OPTION && !philo->over_mustcount \
		&& must_eat <= get_eat_count(philo))
	{
		philo->over_mustcount = true;
		pthread_mutex_lock(philo->data->data_mutex);
		philo->data->ended_nums++;
		pthread_mutex_unlock(philo->data->data_mutex);
	}
	if (safe_usleep(philo->arg->time_to_eat * MS_TO_US, \
		philo->data))
		return (ERR);
	return (SUCCESS);
}

#include <stdio.h>
void	take_one_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (safe_printf(philo, MSG_FORK))
	{
		pthread_mutex_unlock(philo->first_fork);
		set_err_flag(philo->data);
		return ;
	}
	while (1)
	{
		if (update_now_ms(philo->data))
		{
			set_err_flag(philo->data);
			break ;
		}
		if (is_end(philo->data))
			break ;
		if (safe_usleep(SHORT_TIME, philo->data))
			break ;
	}
	pthread_mutex_unlock(philo->first_fork);
}
