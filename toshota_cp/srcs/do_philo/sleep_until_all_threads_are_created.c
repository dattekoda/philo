#include "philo_func.h"
#define MAIN_THREAD_COUNT 1

static bool	are_all_philosophers_born(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->born_count_mutex);
	if (philo->common->born_count == \
	philo->common->number_of_philosophers + MAIN_THREAD_COUNT)
		return (pthread_mutex_unlock(&philo->common->born_count_mutex), true);
	pthread_mutex_unlock(&philo->common->born_count_mutex);
	return (false);
}

static bool	set_time_to_start_do_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->time_to_start_do_philo_mutex);
	philo->common->time_to_start_do_philo = get_current_time();
	if (philo->common->time_to_start_do_philo == -1)
		return (pthread_mutex_unlock \
		(&philo->common->time_to_start_do_philo_mutex), false);
	return (pthread_mutex_unlock \
	(&philo->common->time_to_start_do_philo_mutex), true);
}

bool	sleep_until_all_threads_are_created(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->born_count_mutex);
	philo->common->born_count++;
	if (set_time_to_start_do_philo(philo) == false)
		return (pthread_mutex_unlock \
			(&philo->common->born_count_mutex) == false);
	pthread_mutex_unlock(&philo->common->born_count_mutex);
	while (true)
	{
		if (are_all_philosophers_born(philo) == true)
			break ;
	}
	return (true);
}
