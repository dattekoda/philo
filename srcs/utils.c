/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:17:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 11:52:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_in_ms(void)
{
	int				ms;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_putendl_err("gettimeofday"), ERR);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

int	simple_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str && '0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (*str)
		return (-1);
	return (num);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	printf("%ld", ft_atol(argv[1]));
// 	return (0);
// }

int	print_state(t_philo *ph, char *state)
{
	if (pthread_mutex_lock(&ph->data->print_mutex))
		return (ft_putendl_err(ERR_LOCK), ERR);
	if (printf("%ld %d %s\n", ph->now_ms,
		ph->idx, state) < 0)
		return (ft_putendl_err(ERR_PRINTF), ERR);
	if (pthread_mutex_unlock(&ph->data->print_mutex))
		return (ft_putendl_err(ERR_LOCK), ERR);
	return (SUCCESS);
}

int	high_prec_usleep(int ms)
{
	int	start;

	start = get_time_in_ms();
	if (start < 0)
		return (ERR);
	while (get_time_in_ms() < start + ms)
		if (usleep(200))
			return (ft_putendl_err("usleep"), ERR);
	return (SUCCESS);
}
