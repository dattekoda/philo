/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 15:51:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

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
			return (NULL);
		philo->data->ended_nums++;
		if (pthread_mutex_unlock(philo->data->data_mutex))
			return (NULL);
	}
	return (0);
}

int	check_if_end(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->arg->number_of_times_each_philosopher_must_eat != NO_OPTION && \
		philo->arg->number_of_times_each_philosopher_must_eat <= philo->eat_count)
		philo->data->ended_nums++;
	if (philo->arg->number_of_times_each_philosopher_must_eat == -1)
	while (++i < philo->arg->number_of_philosophers)
	{
	}
}