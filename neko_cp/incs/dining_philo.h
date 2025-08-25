#ifndef DINING_PHILO_H
# define DINING_PHILO_H

# include <pthread.h>

typedef struct	s_dining_philo_args
{
	long		len;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		must_eat;
}				t_dining_philo_args;

int				dining_philo(t_dining_philo_args *args);

#endif