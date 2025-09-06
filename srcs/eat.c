/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:25:19 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 18:45:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"

static int	update_eat(t_philo *philo);
static int	take_forks(t_philo *philo, pthread_mutex_t *f);

int	do_eat(t_philo *philo)
{
	pthread_mutex_t	*f;

	f = philo->data->fork_mutex;
	if (take_forks(philo, f))
		return (ERR);
	if (update_eat(philo))
		return (pthread_mutex_unlock(f + philo->right_fork_id), \
		pthread_mutex_unlock(f + philo->left_fork_id), ERR);
	pthread_mutex_unlock(f + philo->left_fork_id);
	pthread_mutex_unlock(f + philo->right_fork_id);
	if (update_dead_flag(philo))
		return (ERR);
	return (SUCCESS);
}

static int	take_forks(t_philo *philo, pthread_mutex_t *f)
{
	pthread_mutex_lock(f + philo->right_fork_id);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(f + philo->right_fork_id), ERR);
	if (philo->arg->number_of_philosophers == 1)
		return (pthread_mutex_unlock(f + philo->right_fork_id), SUCCESS);
	pthread_mutex_lock(f + philo->left_fork_id);
	if (safe_printf(philo, MSG_FORK))
		return (pthread_mutex_unlock(f + philo->right_fork_id), \
		pthread_mutex_unlock(f + philo->left_fork_id), ERR);
	return (SUCCESS);
}

static int	update_eat(t_philo *philo)
{
	int	must_eat;

	if (safe_printf(philo, MSG_EAT))
		return (ERR);
	if (safe_usleep(philo->arg->time_to_eat * MS_TO_US))
		return (ERR);
	philo->eat_count++;
	must_eat = philo->arg->number_of_times_each_philosopher_must_eat;
	if (must_eat == NO_OPTION)
		return (SUCCESS);
	if (!philo->over_mustcount && must_eat <= philo->eat_count)
	{
		philo->over_mustcount = true;
		pthread_mutex_lock(philo->data->end_mutex);
		philo->data->ended_nums++;
		pthread_mutex_unlock(philo->data->end_mutex);
	}
	return (SUCCESS);
}
