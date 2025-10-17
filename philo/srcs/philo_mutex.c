/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:36:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/16 14:42:54 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

// update last time to eat
void	update_ltte(t_philo *philo, uint64_t now_ms)
{
	pthread_mutex_lock(philo->philo_mutex);
	philo->last_time_to_eat = now_ms;
	pthread_mutex_unlock(philo->philo_mutex);
}

uint64_t	get_ltte(t_philo *philo)
{
	uint64_t	ltte;

	pthread_mutex_lock(philo->philo_mutex);
	ltte = philo->last_time_to_eat;
	pthread_mutex_unlock(philo->philo_mutex);
	return (ltte);
}

void	update_eat_count(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(philo->philo_mutex);
}

int	get_eat_count(t_philo *philo)
{
	int	count;

	pthread_mutex_lock(philo->philo_mutex);
	count = philo->eat_count;
	pthread_mutex_unlock(philo->philo_mutex);
	return (count);
}
