#ifndef PHILO_FUNC_H
# define PHILO_FUNC_H

# include "utils.h"

// do_philo
// do_philo.c
void	*do_philo(t_philo *philo);
// do_something.c
bool	do_eat(t_philo *philo);
void	do_think(t_philo *philo);
void	do_sleep(t_philo *philo);
// sleep_until_all_threads_are_created.c
bool	sleep_until_all_threads_are_created(t_philo *philo);
// take_a_fork.c
bool	do_take_a_fork(t_philo *philo);
void	put_forks(t_philo *philo);

// end_philo
// destroy_all_mutex.c
bool	destroy_all_mutex(t_philo *philo);
// end_philo.c
bool	is_died(t_philo *philo);
bool	is_end(t_philo *philo);
void	free_philo(t_philo *philo);
// is_end.c
bool	is_everyone_full(t_philo *philo);
void	monitor_philo(t_philo *philo);
void	end_philo(t_philo *philo);

// get_philo
// get_philo.c
t_philo	*get_philo(int argc, char **argv);
// init_all_mutex.c
bool	init_all_mutex(t_philo *philo);
// init_philo.c
t_philo *init_philo(int argc, char **argv);

// is_arg_valid/is_arg_valid.c
bool	is_arg_valid(int argc, char **argv);

#endif