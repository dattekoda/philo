#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__take_left_fork(t_philo *self)
{
	if (~self->_is_using_fork & 0b10)
		pthread_mutex_lock(self->_left_fork);
	self->_is_using_fork |= 0b10;
	if (!philo__get_active(self))
		return (-1);
	philo__put_msg(self, MSG_TAKEN_FORK, 0);
	return (0);
}