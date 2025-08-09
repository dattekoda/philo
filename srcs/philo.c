/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:55:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 09:58:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_odd(void	*arg)
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
void	*routine_even(void	*arg)
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
		left = pthread_mutex_lock(&ph->data->fork[(ph->idx + 1) % ph->data->num_philo]);
		if (!left)
			print_state(ph->data, (ph->idx + 1) % ph->data->num_philo, STATE_FORK);
		right = pthread_mutex_lock(&ph->data->fork[ph->idx]);
		if (!right)
			print_state(ph->data, ph->idx, STATE_FORK);
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
	while (++i < data->num_philo)
	{
		if (i % 2 == 0 && pthread_create(&threads[i], NULL, routine_even, &philos[i]))
		{
			print_state(data, i, STATE_DIE);
			break ;
		}
		if (i % 2 == 1 && pthread_create(&threads[i], NULL, routine_odd, &philos[i]))
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
