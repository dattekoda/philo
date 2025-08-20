#include "philo_func.h"

static bool	all_pthread_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->common->number_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, (void *)do_philo, &philo[i]);
		i++;
	}
	return (true);
}

t_philo *get_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = init_philo(argc, argv);
}