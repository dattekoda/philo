#include "philo_func.h"

static t_philo_common	*store_arg_in_each_of_philo(int argc, char **argv)
{
	t_philo_common	*common;

	common = (t_philo_common *)malloc(sizeof(t_philo_common));
	if (check_malloc(common) == NULL)
		return (NULL);
	common->number_of_philosophers = 
}

static bool	store_arg_in_each_of_philo(int argc, char **argv, t_philo *philo,
		int number_of_philosophers)
{
	int				i;
	t_philo_common	*common;

	i = 0;
	common = store_arg_in_philo_common(argc, argv);
	while (i < number_of_philosophers)
	{
		philo[i] = (t_philo){
			i + INITIAL_VALUE,
			0,
			0,
			init_fork_id(philo, i, number_of_philosophers),
			common};
		i++;
	}
}

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;
	int		number_of_philosophers;

	number_of_philosophers = ft_atoi(argv[1]);
	philo = (t_philo *)malloc(sizeof(t_philo) * number_of_philosophers);
	if (check_malloc(philo) == NULL)
		return (NULL);
	if (store_arg_in_each_of_philo(argc, argv, philo,
			number_of_philosophers) == false)
		return (free(philo), NULL);
	return (philo);
}
