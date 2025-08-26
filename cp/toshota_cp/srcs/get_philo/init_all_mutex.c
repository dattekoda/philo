#include "philo.h"

static bool	pthread_last_time_to_eat_mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->common->number_of_philosophers)
	{
		if (pthread_mutex_init(&philo[i].last_time_to_eat_mutex, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

static bool	pthread_fork_mutex_init(t_philo *philo)
{
	int	i;

	i = INITIAL_VALUE;
	philo->common->fork_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (philo->common->number_of_philosophers + 1));
	if (check_malloc(philo->common->fork_mutex) == NULL)
		return (false);
	while (i <= philo->common->number_of_philosophers)
	{
		if (pthread_mutex_init(&philo->common->fork_mutex[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	init_all_mutex(t_philo *philo)
{
	bool	ret;

	ret = true;
	if (pthread_mutex_init(&(philo->common->born_count_mutex), NULL) != 0)
		ret = false;
	if (pthread_mutex_init(&(philo->common->full_count_mutex), NULL) != 0)
		ret = false;
	if (pthread_mutex_init(&(philo->common->print_mutex), NULL) != 0)
		ret = false;
	if (pthread_mutex_init(&(philo->common->death_flag_mutex), NULL) != 0)
		ret = false;
	if (pthread_mutex_init(&(philo->common->time_to_start_do_philo_mutex),
			NULL) != 0)
		ret = false;
	if (pthread_last_time_to_eat_mutex_init(philo) == false)
		ret = false;
	if (pthread_fork_mutex_init(philo) ==false)
		ret = false;
	if (ret == false)
		ft_putstr_fd("failed to pthread_mutex_init", STDERR_FILENO);
	return (ret);
}
