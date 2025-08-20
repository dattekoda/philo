#include "utils.h"

bool	put_msg(t_philo *philo, char *msg)
{
	int	time;

	// if (is_end(philo) == true)
	// 	return (true);
	time = get_current_time();
	if (time == -1)
		return (false);
	pthread_mutex_lock(&philo->common->time_to_start_do_philo_mutex);
	time -= philo->common->time_to_start_do_philo;
	pthread_mutex_unlock(&philo->common->time_to_start_do_philo_mutex);
	pthread_mutex_lock(&philo->common->print_mutex);
	printf("%d %d %s", time, philo->philo_nb, msg);
	pthread_mutex_unlock(&philo->common->print_mutex);
	if (!ft_strcmp(msg, DIED))
	{
		pthread_mutex_lock(&philo->common->death_flag_mutex);
		philo->common->death_flag = true;
		pthread_mutex_unlock(&philo->common->death_flag_mutex);
	}
	return (true);
}
