#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__take_fork(t_philo *self)
{
	int	(*actions[2])(t_philo *);

	actions[0] = philo__take_left_fork;
	actions[1] = philo__take_right_fork;
	if (actions[self->_nbr % 2 != 0](self))
		return (-1);
	if (self->_table->_len == 1)
	{
		while (1)
		{
			if (!philo__get_active(self))
				return (-1);
			usleep(1);
		}
	}
	if (actions[self->_nbr % 2 == 0](self))
		return (-1);
	return (0);
}

