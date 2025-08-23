#include "philo_func.h"

static bool	is_even(int num)
{
	return (num % 2 == 0);
}

void	*do_philo(t_philo *philo)
{
	if (sleep_until_all_threads_are_created(philo) == false)
		return (NULL);
	if (is_even(philo->philo_nb))
		ft_usleep((philo->common->time_to_eat / 2) * 1000);
	while (true)
	{
		if (do_take_a_fork(philo) == false)
			break ;
		if (do_eat(philo) == false)
			return (NULL) ;
		if (is_died(philo) || is_end(philo))
			break ;
		do_sleep(philo);
		if (is_died(philo) || is_end(philo))
			break ;
		do_think(philo);
		if (is_died(philo) || is_end(philo))
			break ;
	}
	return (NULL);
}
