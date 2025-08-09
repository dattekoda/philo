/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:55:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 00:14:54 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*arg)
{
	t_philo	*ph;
	int		left;
	int		right;

	ph = (t_philo *)arg;
	while (1)
	{
		ph->data->now_ms = get_time_in_ms() - ph->data->start_ms;
		if (ph->data->time_to_die < ph->last_time_to_eat - ph->data->now_ms)
			return ("die");
		right = pthread_mutex_lock(&ph->data->fork[ph->idx]);
		if (!right)
			print_state(ph->data, ph->idx, STATE_FORK);
		left = pthread_mutex_lock(&ph->data->fork[(ph->idx + 1) % ph->data->num_philo]);
		if (!left)
			print_state(ph->data, (ph->idx + 1) % ph->data->num_philo, STATE_FORK);
		if (!left && !right)
		{
			print_state(ph->data, ph->idx, STATE_EAT);
			high_prec_msleep(ph->data->time_to_eat);
			pthread_mutex_unlock(&ph->data->fork[ph->idx]);
			pthread_mutex_unlock(&ph->data->fork[(ph->idx + 1) % ph->data->num_philo]);
		}
	}
	return (NULL);
}

// this func is main
int	philosopher(t_data *data)
{
	t_philo		*philos;
	pthread_t	*threads;
	int			i;

	if (set_philos(data, &philos))
		return (ERR);
	threads = malloc(sizeof(pthread_t) * data->num_philo);
	if (!threads)
		return (ERR);
	i = -1;
	data->start_ms = get_time_in_ms();
	data->now_ms = data->start_ms;
	while (++i < data->num_philo)
	{
		if (pthread_create(&threads[i], NULL, routine, &philos[i]))
		{
			print_state(data, i, STATE_DIE);
			break ;
		}
	}
	i = -1;
	while (++i < data->num_philo)
		pthread_join(threads[i], NULL);
	return (free(philos), SUCCESS);
}
