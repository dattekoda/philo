/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/11 18:06:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "define.h"
#include "msg.h"
#include "utils.h"
#include "checker.h"

static void	update_dead_flag(t_philo *philo);
static void	check_must_eat(t_philo *philo);

void	set_err_flag(t_data *data)
{
	if (is_err(data))
		return ;
	pthread_mutex_lock(data->err_mutex);
	data->err_flag = true;
	pthread_mutex_unlock(data->err_mutex);
}

// end 1 not yet 0
int	check_if_end(t_philo *philo)
{
	pthread_mutex_lock(philo->data->data_mutex);
	update_dead_flag(philo);
	if (is_end(philo->data))
		return (pthread_mutex_unlock(philo->data->data_mutex), END);
	check_must_eat(philo);
	if (is_end(philo->data))
		return (pthread_mutex_unlock(philo->data->data_mutex), END);
	return (pthread_mutex_unlock(philo->data->data_mutex), NOT_END);
}

static void	update_dead_flag(t_philo *philo)
{
	if (philo->arg->time_to_die + philo->last_time_to_eat \
		> get_now_ms(philo->data) || is_end(philo->data))
		return ;
	philo->dead = true;
	safe_printf(philo, MSG_DIE);
	pthread_mutex_lock(philo->data->end_mutex);
	philo->data->end_flag = true;
	pthread_mutex_unlock(philo->data->end_mutex);
}

static void	check_must_eat(t_philo *philo)
{
	if (philo->arg->number_of_times_each_philosopher_must_eat != NO_OPTION \
		&& philo->data->ended_nums == philo->arg->number_of_philosophers)
	{
		pthread_mutex_lock(philo->data->end_mutex);
		philo->data->end_flag = true;
		pthread_mutex_unlock(philo->data->end_mutex);
	}
}
