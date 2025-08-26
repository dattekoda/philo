#include "philo_func.h"

bool	is_died(t_philo *philo)
{
	int	current_time;

	if (philo->common->number_of_philosophers == 1)
		return (ft_usleep(philo->common->time_to_die * 1000), \
		put_msg(philo, DIED), true);
	current_time = get_current_time();
	if (current_time == -1)
		return (true);
	pthread_mutex_lock(&philo->common->time_to_start_do_philo_mutex);
	current_time -= philo->common->time_to_start_do_philo;
	pthread_mutex_unlock(&philo->common->time_to_start_do_philo_mutex);
	pthread_mutex_lock(&philo->last_time_to_eat_mutex);
	if (current_time - philo->last_time_to_eat > philo->common->time_to_die)
		return (pthread_mutex_unlock(&philo->last_time_to_eat_mutex), \
		put_msg(philo, DIED), true);
	return (pthread_mutex_unlock(&philo->last_time_to_eat_mutex), false);
}

static bool	is_someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->death_flag_mutex);
	if (philo->common->death_flag == true)
		return (pthread_mutex_unlock(&philo->common->death_flag_mutex), true);
	return (pthread_mutex_unlock(&philo->common->death_flag_mutex), false);
}

// why is this func not static?
bool	is_everyone_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->full_count_mutex);
	if (philo->common->full_count == philo->common->number_of_philosophers)
		return (pthread_mutex_unlock(&philo->common->full_count_mutex), true);
	return (pthread_mutex_unlock(&philo->common->full_count_mutex), false);
}

bool	is_end(t_philo *philo)
{
	return (is_someone_dead(philo) || is_everyone_full(philo));
}
