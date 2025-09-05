/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 15:40:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"
#include "utils.h"

int	wait_until_all_threads_created(t_philo *philo)
{
	if (pthread_mutex_lock(philo->data->data_mutex))
		return (ERR);
	philo->data->created++;
	if (get_millisedonds_time(&philo->data->start_ms))
		return (pthread_mutex_unlock(philo->data->data_mutex), ERR);
	philo->data->now_ms = philo->data->start_ms;
	if (pthread_mutex_unlock(philo->data->data_mutex))
		return (ERR);
	while (1)
	{
		if (philo->data->created + 1 == philo->arg->number_of_philosophers)
			break ;
		if (safe_usleep(100))
			return (ERR);
	}
	return (SUCCESS);
}

int	is_odd(t_philo *philo)
{
	if (philo->idx % 2 == 1)
	{
		if (safe_usleep(philo->arg->time_to_eat * 500))
			return (ERR);
	}
}

int	do_eat(t_philo *philo)
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	right = philo->data->fork_mutex + philo->idx;
	left = philo->data->fork_mutex + ((philo->idx + 1) % philo->idx);
	if (pthread_mutex_lock(right))
		return (ERR);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(right), ERR);
	if (pthread_mutex_lock(left))
		return (pthread_mutex_unlock(right), ERR);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(right), pthread_mutex_unlock(left), ERR);
	if (safe_printf(philo, MSG_EAT))
		return (pthread_mutex_unlock(right), pthread_mutex_unlock(left), ERR);
	philo->eat_count++;
	if (pthread_mutex_unlock(left))
		return (pthread_mutex_unlock(right), ERR);
	if (pthread_mutex_unlock(right))
		return (ERR);
	return (SUCCESS);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_until_all_threads_created(philo))
		return (NULL);
	if (is_odd(philo))
		return (NULL);
	while (1)
	{
		if (do_eat(philo))
			return (NULL);
		if (check_if_end())
	}
}