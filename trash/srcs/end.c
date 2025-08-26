/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:56:26 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/19 16:18:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_end(t_philo *ph)
{
	int	i;

	if (ph->data->optional)
	{
		if (pthread_mutex_lock(&ph->mutex->list_mutex))
			exit_philo(ph, ERR_LOCK);
		i = 0;
		while (i < ph->data->num_philo
			&& ph->data->num_times_eat <= ph->data->list_eat_nums[i])
			i++;
		if (i == ph->data->num_philo)
			return (pthread_mutex_unlock(&ph->mutex->list_mutex), END);
		if (pthread_mutex_unlock(&ph->mutex->list_mutex))
			exit_philo(ph, ERR_UNLOCK);
	}
	return (SUCCESS);
}

int	is_dead(t_philo *ph)
{
	ph->now_ms = get_time_in_ms() - ph->data->start_ms;
	if (ph->data->time_die <= ph->now_ms - ph->last_eat)
	{
		print_state(ph, STATE_DIE);
		return (END);
	}
	return (SUCCESS);
}
