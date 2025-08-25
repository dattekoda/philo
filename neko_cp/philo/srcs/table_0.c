#include "philo.h"
#include "table.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

static int		init(t_table *self, t_table_args *args);
static int		del(t_table *self);
static t_philo	*create_philos(t_table *self);

int	table__init(t_table *self, t_table_args *args)
{
	int	result;

	result = init(self, args);
	if (result)
		del(self);
	return (result);
}

int	table_del(t_table *self)
{
	return (del(self));
}

static int	init(t_table *self, t_table_args *args)
{
	memset(self, 0, sizeof(*self));
	self->_len = args->len;
	self->_time_to_die = args->time_to_die;
	self->_time_to_eat = args->time_to_eat;
	self->_time_to_sleep = args->time_to_sleep;
	self->_must_eat = args->must_eat;
	self->_lock_printf = mutex_new(1);
	if (!self->_lock_printf)
		return (-1);
	if (self->_len % 2) // weird variable, snooze
		self->_snooze = self->_time_to_eat / (double)(self->_len / 2);
	self->_lock = mutex_new(1);
	if (!self->_lock)
		return (-1);
	self->_forks = mutex_new(self->_len);
	if (!self->_forks)
		return (-1);
	self->__forks_len = self->_len;
	self->_philos = create_philos(self);
	if (!self->_philos)
		return (-1);
}

static int	del(t_table *self)
{
	while (self->_philos && self->_len--)
		philo__del(&self->_philos[self->_len]);
	free(self->_philos);
	while (self->__forks_len--)
		pthread_mutex_destoy(&self->_forks[self->__forks_len]);
	free(self->_forks);
	mutex_del(self->_lock);
	mutex_del(self->_lock_printf);
	return (0);
}

static t_philo	*create_philos(t_table *self)
{
	t_philo_args	args;
	t_philo			*philos;
	size_t			i;

	philos = malloc(sizeof(t_philo [self->_len]));
	if (!philos)
		return (NULL);
	args.table = self;
	i = 0;
	while (i < self->_len)
	{
		args.nbr = i + 1;
		args.left_fork = &self->_forks[i];
		args.right_fork = &self->_forks[(i - 1) % self->_len];
		if (philo__init(&philos[i], &args))
		{
			while (--i)
				philo__del(&philos[i]);
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
