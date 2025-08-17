/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:55:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 17:53:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (pthread_create(&threads[i], NULL, routine, &philos[i]))
			return (free(philos), ERR);
	i = -1;
	while (++i < data->num_philo)
		pthread_join(threads[i], NULL);
	return (free(philos), SUCCESS);
}
