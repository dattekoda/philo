#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	init(t_philo *self, t_philo_args *args);
static int	del(t_philo *self);

int	philo_init(t_philo *self, t_philo_args *args)
{
	int	result;

	result = init(self, args);
	if (result)
		del(self);
	return (result);
}

int	philo_del(t_philo *self)
{
	return (del(self));
}

static int	init(t_philo *self, t_philo_args *args)
{
	memset(self, 0, sizeof(*self));
	self->_nbr = args->nbr;
	self->_table = args->table;
	self->_left_fork = args->left_fork;
	self->_right_fork = args->right_fork;
	self->_lock = mutex_new(1);
	if (!self->_lock)
		return (-1);
	return (0);
}

static int	del(t_philo *self)
{
	return (mutex_del(self->_lock));
}
