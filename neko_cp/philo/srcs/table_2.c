#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	table__put_msg(t_table *self, int nbr, char *msg, int enforce)
{
	pthread_mutex_lock(self->_lock);
	pthread_mutex_lock(self->_lock_printf);
	if (enforce || self->is_running)
		printf("%ld %d %s\n", table__get_time(self), nbr, msg);
	pthread_mutex_unlock(self->_lock_printf);
	pthread_mutex_unlock(self->_lock);
}

long	table__get_time(t_table *self)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (timeval2ms(interval(now, self->start_time)));
}

int	table__check_died(t_table *self)
{
	int		isdied;
	t_philo	*philo;
	size_t	i;

	i = 0;
	while (i < self->_len)
	{
		philo = &self->_philos[i++];
		pthread_mutex_lock(philo->_lock);
		isdied = (0 <= philo->last_ate_time && philo->last_ate_time \
			+ self->_time_to_die < table__get_time(self));
		pthread_mutex_unlock(philo->_lock);
		if (isdied)
			return (philo->_nbr);
	}
	return (0);
}
