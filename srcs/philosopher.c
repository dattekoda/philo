/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:13:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/30 12:25:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(t_arg *arg)
{
	t_data	data;
	t_philo	*philo;

	if (init_data(&data, arg))
		return (ERR);
	if (init_philo(&philo, &data))
		return (free_data(&data), ERR);
	if (routine(philo))
		return (free(philo), free_data(&data), ERR);
	return (free(philo), free_data(&data), SUCCESS);
}
