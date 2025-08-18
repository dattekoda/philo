/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:10:47 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 15:22:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_philo(t_philo *philo, char *str)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philo)
		pthread_mutex_unlock(&philo->mutex->fork_mutex[i]);
	i = -1;
	while (++i < philo->data->num_philo)
		pthread_mutex_destroy(&philo->mutex->fork_mutex[i]);
	if (!str)
		ft_putendl_err(str);
	exit(FAILURE);
}
