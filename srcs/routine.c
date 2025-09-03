/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/03 15:55:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	wait_until_all_threads_created(t_philo *philo)
{
	if (pthread_mutex_lock(philo->data->data_mutex))
		return (ERR);
	philo->data->created++;
	if (pthread_mutex_unlock(philo->data->data_mutex))
		return (ERR);
	while (1)
	{
		if (philo->data->created + 1 == philo->arg->number_of_philosophers)
			break ;
		safe_usleep()
	}
	return (SUCCESS);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_until_all_threads_created(philo))
		return (NULL);
	while (1)
	{
		;
	}
}