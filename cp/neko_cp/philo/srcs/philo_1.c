#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__start(t_philo *self)
{
	pthread_mutex_lock(self->_lock);
	while (1)
	{
		self->_thread = thread_start((void *)philo__routine, self);
		if (!self->_thread)
			break ;
		self->active = 1;
		pthread_mutex_unlock(self->_lock);
		return (0);
	}
	pthread_mutex_unlock(self->_lock);
	return (-1);
}

int	philo__wait(t_philo *self)
{
	return (thread_join(self->_thread, NULL));
}

void	*philo__routine(t_philo *self)
{
	if (self->_table->_snooze)
	{
		if (!philo__get_active(self))
			return (NULL);
		msleep(self->_table->_snooze
			* reverse_even_odd(self->_nbr - 1, self->_table->_len));
	}
	while (1)
	{
		if (philo__do_to_eat(self))
			break ;
		if (philo__do_to_sleep(self))
			break ;
		if (philo__do_to_think(self))
			break ;
	}
	philo__put_fork(self);
	return (NULL);
}
