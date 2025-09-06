/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:13:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 19:37:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <stdlib.h> // free malloc

static int	born_to_be_thread(t_philo *philo, pthread_t *thread);

int	philosopher(t_arg *arg)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;

	if (init_data(&data, arg))
		return (ERR);
	if (init_philo(&philo, &data, arg))
		return (free_data(&data), ERR);
	thread = malloc(sizeof(pthread_t) * arg->number_of_philosophers);
	if (!thread)
		return (free_data(&data), free(philo), ERR);
	if (born_to_be_thread(philo, thread))
		return (free_data(&data), free(philo), ERR);
	return (free(philo), free_data(&data), SUCCESS);
}

static int	born_to_be_thread(t_philo *philo, pthread_t *thread)
{
	int		i;

	i = -1;
	while (++i < philo->arg->number_of_philosophers)
	{
		if (pthread_create((thread + i), NULL, routine, philo + i))
		{
			set_err_flag(philo->data);
			while (0 < i--)
				pthread_join(*(thread + i), NULL);
			return (msg_function_err(ERR_MSG_CREATE), ERR);
		}
	}
	i = -1;
	while (++i < philo->arg->number_of_philosophers)
	{
		if (pthread_join(*(thread + i), NULL))
			return (msg_function_err(ERR_MSG_JOIN), ERR);
	}
	if (philo->data->err_flag)
		return (ERR);
	return (SUCCESS);
}
