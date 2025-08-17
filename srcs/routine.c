/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:50:55 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/17 16:17:46 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	wait_until_all_set(t_data *data)
// {
// 	pthread_mutex_lock()
// }

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	// if (wait_until_all_set(ph->data))
	// 	return (ERR);
	while (1)
	{
		ph->now_ms = get_time_in_ms();
		
	}
}
