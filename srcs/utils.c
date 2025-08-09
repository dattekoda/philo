/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:17:22 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 10:00:12 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	long			ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	ft_putendl_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(STDERR_FILENO, str, i);
	write(STDERR_FILENO, "\n", 1);
}

long	ft_atol(char *str)
{
	long	num;

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

int	print_state(t_data *data, int idx, char *state)
{
	return (printf("%ld %d %s\n", data->now_ms,
		idx, state));
}

void	high_prec_msleep(long ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() < start + ms)
		usleep(200);
}
