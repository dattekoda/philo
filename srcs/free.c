/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:05:11 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 16:49:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&data->fork_mutex[i]);
	free(data->fork_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}
