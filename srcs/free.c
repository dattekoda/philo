/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:05:11 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 15:43:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data->optional)
		free(data->list_eat_nums);
}

void	free_philo(t_data *data, t_mutex *mutex)
{
	int	i;

	free_data(data);
	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&mutex->fork_mutex[i]);
	free(mutex->fork_mutex);
	pthread_mutex_destroy(&mutex->print_mutex);
}
