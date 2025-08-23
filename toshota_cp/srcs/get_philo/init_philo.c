#include "philo_func.h"

// why is not init_fork_id static?
void	init_fork_id(t_philo *philo, int order, int number_of_philosophers)
{
	if (order == 0)
	{
		philo[order].right_fork_id = number_of_philosophers;
		philo[order].left_fork_id = INITIAL_VALUE;
	}
	else
	{
		philo[order].right_fork_id = philo[order - 1].left_fork_id;
		philo[order].left_fork_id = philo[order].right_fork_id + 1;
	}
}

static bool	init_fork(t_philo_common *common)
{
	int	i;

	common->fork = (bool *)malloc(sizeof(bool)
			* (common->number_of_philosophers + 1));
	if (check_malloc(common->fork) == NULL)
		return (false);
	i = INITIAL_VALUE;
	while (i <= common->number_of_philosophers)
	{
		common->fork[i] = AVAILABLE;
		i++;
	}
	return (true);
}

static t_philo_common	*store_arg_in_philo_common(int argc, char **argv)
{
	t_philo_common	*common;

	common = (t_philo_common *)malloc(sizeof(t_philo_common));
	if (check_malloc(common) == NULL)
		return (NULL);
	common->number_of_philosophers = ft_atoi(argv[1]);
	common->time_to_die = ft_atoi(argv[2]);
	common->time_to_eat = ft_atoi(argv[3]);
	common->time_to_sleep = ft_atoi(argv[4]);
	common->death_flag = false;
	common->born_count = 0;
	common->full_count = 0;
	if (argc == 6)
		common->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		common->number_of_times_each_philosopher_must_eat = \
		NO_MIN_NUM_OF_PHILO_MUST_EAT;
	if (init_fork(common) == false)
		return (free(common), NULL);
	return (common);
}

static bool	store_arg_in_each_of_philo(int argc, char **argv, t_philo *philo,
		int number_of_philosophers)
{
	int				i;
	t_philo_common	*common;

	i = 0;
	common = store_arg_in_philo_common(argc, argv);
	if (common == NULL)
		return (false);
	while (i < number_of_philosophers)
	{
		philo[i].philo_nb = i + INITIAL_VALUE;
		philo[i].last_time_to_eat = 0;
		philo[i].count_to_eat = 0;
		init_fork_id(philo, i, number_of_philosophers);
		philo[i].common = common;
		i++;
	}
	return (true);
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
