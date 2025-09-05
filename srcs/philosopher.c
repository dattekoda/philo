/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:13:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 22:22:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(t_arg *arg)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;
	int			i;
	int			ret;

	if (init_data(&data, arg))
		return (ERR);
	if (init_philo(&philo, &data))
		return (free_data(&data), ERR);
	thread = malloc(sizeof(pthread_t) * arg->number_of_philosophers);
	i = -1;
	while (++i < arg->number_of_philosophers)
	{
		if (pthread_create((thread + i), NULL, routine, philo + i))
		{
			while (0 < i--)
				pthread_join(thread + i, NULL);
			return (free(thread), free(philo), free_data(&data), ERR);
		}
	}
	i = 0;
	while (1)
	{
		if (pthread_join(thread + i, &ret))
			return (free(thread), free(philo), free_data(&data), ERR);
		if (ret)
			return (free(thread), free(philo), free_data(&data), ERR);
		i = (i + 1) % arg->number_of_philosophers;
	}
	return (free(philo), free_data(&data), SUCCESS);
}
