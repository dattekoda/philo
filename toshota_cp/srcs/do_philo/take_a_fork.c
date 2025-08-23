#include "philo_func.h"

static void	set_fork_id_depending_on_philo_nb(t_philo *philo, \
int	*dominant_side_fork_id, int *non_dominant_side_fork_id)
{
	*dominant_side_fork_id = philo->left_fork_id;
	*non_dominant_side_fork_id = philo->right_fork_id;
}

static void	take_one_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->common->fork_mutex[fork_id]);
	philo->common->fork[fork_id] = UNAVAILABLE;
	put_msg(philo, TAKING_A_FORK);
}

void	put_forks(t_philo *philo)
{
	philo->common->fork[philo->right_fork_id] = AVAILABLE;
	philo->common->fork[philo->left_fork_id] = AVAILABLE;
	pthread_mutex_unlock(&philo->common->fork_mutex[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->common->fork_mutex[philo->left_fork_id]);
}

// should be renamed "do_take_forks" or be devided
bool	do_take_a_fork(t_philo *philo)
{
	int	dominant_side_fork_id;
	int	non_dominant_side_fork_id;

	set_fork_id_depending_on_philo_nb \
	(philo, &dominant_side_fork_id, &non_dominant_side_fork_id);
	take_one_fork(philo, dominant_side_fork_id);
	if (is_died(philo))
		return (pthread_mutex_unlock \
		(&philo->common->fork_mutex[dominant_side_fork_id]), false);
	take_one_fork(philo, non_dominant_side_fork_id);
	if (is_died(philo))
		return (put_forks(philo), false);
	return (true);
}
