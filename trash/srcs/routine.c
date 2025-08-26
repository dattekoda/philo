/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:50:55 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/26 16:20:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

void	update_eat(t_philo *ph)
{
	print_state(ph, STATE_EAT);
	if (high_prec_usleep(ph->data->time_eat))
		exit_philo(ph, NULL);
	if (ph->data->optional)
	{
		if (pthread_mutex_lock(&ph->mutex->list_mutex))
			exit_philo(ph, ERR_LOCK);
		(ph->data->list_eat_nums[ph->idx])++;
		if (pthread_mutex_unlock(&ph->mutex->list_mutex))
			exit_philo(ph, ERR_UNLOCK);
	}
	ph->last_eat = get_time_in_ms() - ph->data->start_ms;
}

void	routine_eat(t_philo *ph)
{
	int	right;
	int	left;

	right = ph->idx;
	left = (ph->idx + 1) % ph->data->num_philo;
	if (pthread_mutex_lock(&ph->mutex->fork_mutex[right]))
		exit_philo(ph, ERR_LOCK);
	print_state(ph, STATE_FORK);
	if (pthread_mutex_lock(&ph->mutex->fork_mutex[left]))
		exit_philo(ph, ERR_LOCK);
	print_state(ph, STATE_FORK);
	update_eat(ph);
	if (pthread_mutex_unlock(&ph->mutex->fork_mutex[left]))
		exit_philo(ph, ERR_UNLOCK);
	if (pthread_mutex_unlock(&ph->mutex->fork_mutex[right]))
		exit_philo(ph, ERR_UNLOCK);
}

void	routine_sleep(t_philo *ph)
{
	print_state(ph, STATE_SLEEP);
	if (high_prec_usleep(ph->data->time_sleep))
		exit_philo(ph, NULL);
}

void	routine_think(t_philo *ph)
{
	print_state(ph, STATE_THINK);
}

void	wait_all_threads(t_philo *ph)
{
	if (pthread_mutex_lock(&ph->mutex->created_num_mutex))
		exit_philo(ph, ERR_LOCK);
	(ph->data->created_num)++;
	if (pthread_mutex_unlock(&ph->mutex->created_num_mutex))
		exit_philo(ph, ERR_UNLOCK);
	while (1)
	{
		if (ph->data->created_num == ph->data->num_philo)
			break ;
		usleep(100);
	}
	if (ph->idx + 1 == ph->data->num_philo)
		ph->data->start_ms = get_time_in_ms();
}

void	is_odd(t_philo *ph)
{
	if (ph->idx % 2 == 1)
		high_prec_usleep(ph->data->time_eat / 2);
}

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	wait_all_threads(ph);
	is_odd(ph);
	while (1)
	{
		ph->now_ms = get_time_in_ms() - ph->data->start_ms;
		routine_eat(ph);
		if (is_end(ph) || is_dead(ph))
			break ;
		routine_sleep(ph);
		if (is_end(ph) || is_dead(ph))
			break ;
		routine_think(ph);
		if (is_end(ph) || is_dead(ph))
			break ;
	}
	return (NULL);
}
