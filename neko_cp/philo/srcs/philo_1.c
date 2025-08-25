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

