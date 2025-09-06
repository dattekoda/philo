/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 21:27:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include <pthread.h>

void	set_err_flag(t_data *data)
{
	if (data->err_flag)
		return ;
	pthread_mutex_lock(data->err_mutex);
	data->err_flag = true;
	pthread_mutex_unlock(data->err_mutex);
}

void	update_dead_flag(t_philo *philo)
{
	if (philo->arg->time_to_die + philo->last_time_to_eat > philo->data->now_ms \
		|| philo->data->end_flag)
		return ;
	philo->dead = true;
	safe_printf(philo, MSG_DIE);
	philo->data->end_flag = true;
	return ;
}

void	check_must_eat(t_philo *philo)
{
	if (philo->arg->number_of_times_each_philosopher_must_eat != NO_OPTION && \
		philo->data->ended_nums == philo->arg->number_of_philosophers)
	philo->data->end_flag = true;
}

// end 1 not yet 0
int	check_if_end(t_philo *philo)
{
	check_must_eat(philo);
	update_dead_flag(philo);
	if (philo->data->end_flag)
		return (END);
	return (NOT_END);
}
