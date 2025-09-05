/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 03:12:54 by khanadat         ###   ########.fr       */
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

int	update_dead_flag(t_philo *philo)
{
	if (pthread_mutex_lock())
	if (philo->arg->time_to_die + philo->last_time_to_eat > philo->data->now_ms \
		|| philo->data->someone_dead)
		return (SUCCESS);
	philo->dead = true;
	safe_printf(philo, MSG_DIE);
	if (pthread_mutex_lock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_LOCK), ERR);
	philo->data->someone_dead = true;
	if (pthread_mutex_unlock(philo->data->data_mutex))
		return (msg_function_err(ERR_MSG_UNLOCK), ERR);
	return (SUCCESS);
}

// end 1 not yet 0
int	check_if_end(t_philo *philo)
{
	if (philo->arg->number_of_times_each_philosopher_must_eat != NO_OPTION &&
		philo->data->ended_nums == philo->arg->number_of_philosophers)
		return (END);
	if (philo->data->someone_dead)
		return (END);
	return (NOT_END);
}
