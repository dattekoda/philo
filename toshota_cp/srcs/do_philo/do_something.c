#include "philo_func.h"

void	do_think(t_philo *philo)
{
	put_msg(philo, THINKING);
}

void	do_sleep(t_philo *philo)
{
	put_msg(philo, SLEEPING);
	ft_usleep(philo->common->time_to_sleep * 1000);
}

static bool	get_last_time_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_time_to_eat_mutex);
	philo->last_time_to_eat = get_current_time();
	if (philo->last_time_to_eat == -1)
		return (pthread_mutex_unlock(&philo->last_time_to_eat_mutex), false);
	pthread_mutex_lock(&philo->common->time_to_start_do_philo_mutex);
	philo->last_time_to_eat -= philo->common->time_to_start_do_philo;
	pthread_mutex_unlock(&philo->common->time_to_start_do_philo_mutex);
	pthread_mutex_unlock(&philo->last_time_to_eat_mutex);
	return (true);
}

bool	do_eat(t_philo *philo)
{
	put_msg(philo, EATING);
	if (get_last_time_to_eat(philo) == false)
		return (false);
	ft_usleep(philo->common->time_to_eat * 1000);
	if (philo->count_to_eat == \
	philo->common->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&philo->common->full_count_mutex);
		philo->common->full_count++;
		pthread_mutex_unlock(&philo->common->full_count_mutex);
	}
	put_forks(philo);
	return (true);
}
