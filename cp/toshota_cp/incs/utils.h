#ifndef UTILS_H
# define UTILS_H

# include "define.h"
# include "ft_func.h"

void	*check_malloc(void *return_value);
bool	put_msg(t_philo *philo, char *msg);
int		get_current_time(void);
int		ft_usleep(int microseconds);

#endif