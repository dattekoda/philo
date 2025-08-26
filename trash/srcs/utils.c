/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:17:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/26 16:20:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

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

void	print_state(t_philo *ph, char *state)
{
	if (pthread_mutex_lock(&ph->mutex->print_mutex))
		exit_philo(ph, ERR_LOCK);
	ph->now_ms = get_time_in_ms() - ph->data->start_ms;
	if (printf("%d %d %s\n", ph->now_ms,
		ph->idx + 1, state) < 0)
		exit_philo(ph, ERR_PRINTF);
	if (pthread_mutex_unlock(&ph->mutex->print_mutex))
		exit_philo(ph, ERR_UNLOCK);
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
