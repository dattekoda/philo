/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:25:19 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 22:45:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"

static int	update_over_mustcount(t_philo *philo);

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
	if (safe_usleep(philo->arg->time_to_eat * MS_TO_US))
		return (pthread_mutex_unlock(right), pthread_mutex_unlock(left), ERR);
	philo->eat_count++;
	if (update_over_mustcount(philo))
		return (ERR);
	if (pthread_mutex_unlock(left))
		return (pthread_mutex_unlock(right), ERR);
	if (pthread_mutex_unlock(right))
		return (ERR);
	if (update_dead_flag(philo))
		return (ERR);
	return (SUCCESS);
}

// success 0 err -1
static int	update_over_mustcount(t_philo *philo)
{
	int	must_eat;

	must_eat = philo->arg->number_of_times_each_philosopher_must_eat;
	if (must_eat == -1)
		return (0);
	if (!philo->over_mustcount && must_eat < philo->eat_count)
	{
		philo->over_mustcount = true;
		if (pthread_mutex_lock(philo->data->data_mutex))
			return (msg_function_err(ERR_MSG_LOCK), ERR);
		philo->data->ended_nums++;
		if (pthread_mutex_unlock(philo->data->data_mutex))
			return (msg_function_err(ERR_MSG_UNLOCK), ERR);
	}
	return (0);
}
