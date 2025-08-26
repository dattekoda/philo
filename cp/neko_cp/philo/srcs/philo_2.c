#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__put_msg(t_philo *self, char *msg, int enforce)
{
	return (table__put_msg(self->_table, self->_nbr, msg, enforce));
}

int	philo__get_active(t_philo *self)
{
	int	active;

	pthread_mutex_lock(self->_table->_lock);
	pthread_mutex_lock(self->_lock);
	self->active &= self->_table->is_running;
	active = self->active;
	pthread_mutex_unlock(self->_lock);
	pthread_mutex_unlock(self->_table->_lock);
	return (active);
}