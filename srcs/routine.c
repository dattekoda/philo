/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:50:55 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 11:48:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	wait_until_all_set(t_data *data)
// {
// 	pthread_mutex_lock()
// }

void	routine_eat(t_philo *ph)
{
	int	right;
	int	left;

	right = ph->idx;
	left = (ph->idx + 1) % ph->data->num_philo;
	if (right < left)
		ft_swap(&left, &right);
	if (pthread_mutex_lock(&ph->data->fork_mutex[left]))
		exit_philo(ph, ERR_LOCK);
	if (print_state(ph, STATE_FORK))
		exit_philo(ph, NULL);
	if (pthread_mutex_lock(&ph->data->fork_mutex[right]))
		exit_philo(ph, ERR_LOCK);
	if (print_state(ph, STATE_FORK))
		exit_philo(ph, NULL);
	if (print_state(ph, STATE_EAT))
		exit_philo(ph, NULL);
	if (high_prec_usleep(ph->data->time_eat))
		exit_philo(ph, NULL);
	ph->last_eat = get_time_in_ms();
	if (pthread_mutex_unlock(&ph->data->fork_mutex[right]))
		exit_philo(ph, ERR_UNLOCK);
	if (pthread_mutex_unlock(&ph->data->fork_mutex[left]))
		exit_philo(ph, ERR_UNLOCK);
}

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	// if (wait_until_all_set(ph->data))
	// 	return (ERR);
	while (1)
	{
		ph->now_ms = get_time_in_ms();
		routine_eat(ph);
	}
}
