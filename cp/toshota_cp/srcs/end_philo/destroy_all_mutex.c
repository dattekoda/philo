#include "philo_func.h"

static bool	pthread_last_time_to_eat_mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->common->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&philo[i].last_time_to_eat_mutex) != 0)
			return (false);
		i++;
	}
	return (true);
}

static bool	pthread_fork_mutex_destroy(t_philo *philo)
{
	int	i;

	i = INITIAL_VALUE;
	while (i < philo->common->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&philo->common->fork_mutex[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	destroy_all_mutex(t_philo *philo)
{
	bool	ret;

	ret = true;
	if (pthread_mutex_destroy(&philo->common->born_count_mutex) != 0)
		ret =false;
	if (pthread_mutex_destroy(&philo->common->full_count_mutex) != 0)
		ret =false;
	if (pthread_mutex_destroy(&philo->common->print_mutex) != 0)
		ret =false;
	if (pthread_mutex_destroy(&philo->common->death_flag_mutex) != 0)
		ret =false;
	if (pthread_mutex_destroy \
	(&philo->common->time_to_start_do_philo_mutex) != 0)
		ret =false;
	if (pthread_last_time_to_eat_mutex_destroy(philo) == false)
		ret = false;
	if (pthread_fork_mutex_destroy(philo) == false)
		ret = false;
	if (ret == false)
		ft_putstr_fd("failed to pthread_mutex_destroy\n", STDERR_FILENO);
	return (ret);
}
