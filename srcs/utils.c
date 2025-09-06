/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:22:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 05:45:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "define.h"
#include "end.h"
#include <unistd.h> // usleep
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#define US_TO_MS 1000
#define S_TO_US 1000000
#define VERY_VERY_SHORT_TIME 10

static int	update_now_ms(t_data *data);
static int	get_useconds_time(uint64_t *time);

// update now_ms and printf philo's action.
int	safe_printf(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->printf_mutex);
	if (update_now_ms(philo->data) || philo->data->err_flag)
		return (pthread_mutex_unlock(philo->data->printf_mutex), ERR);
	if (philo->data->end_flag)
		return (pthread_mutex_unlock(philo->data->printf_mutex), SUCCESS);
	if (printf("%"PRId64" %d %s\n", \
		philo->data->now_ms, philo->idx + 1, msg) < 0)
		return (msg_function_err(ERR_MSG_PRINTF), \
		pthread_mutex_unlock(philo->data->printf_mutex), ERR);
	pthread_mutex_unlock(philo->data->printf_mutex);
	return (SUCCESS);
}

// success 0 error -1
// set time gettimeofday got as ms
int	get_milliseconds_time(uint64_t *time)
{
	if (get_useconds_time(time))
		return (ERR);
	*time /= US_TO_MS;
	return (SUCCESS);
}

// success 0 error -1
int	safe_usleep(uint64_t time, t_data *data)
{
	uint64_t		start;
	uint64_t		now;

	if (get_useconds_time(&start))
		return (set_err_flag(data), ERR);
	now = start;
	while (now < start + time)
	{
		if (usleep(VERY_VERY_SHORT_TIME))
			return (msg_function_err(ERR_MSG_USLEEP), set_err_flag(data), ERR);
		if (get_useconds_time(&now))
			return (set_err_flag(data), ERR);
		if (data->err_flag || data->end_flag)
			break ;
	}
	if (update_now_ms(data))
		return (set_err_flag(data), ERR);
	return (SUCCESS);
}

static int	update_now_ms(t_data *data)
{
	pthread_mutex_lock(data->data_mutex);
	if (get_milliseconds_time(&data->now_ms))
		return (pthread_mutex_unlock(data->data_mutex), ERR);
	data->now_ms = data->now_ms - data->start_ms;
	pthread_mutex_unlock(data->data_mutex);
	return (SUCCESS);
}

static int	get_useconds_time(uint64_t *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (msg_function_err(ERR_MSG_GETTIMEOFDAY), ERR);
	*time = tv.tv_sec * S_TO_US + tv.tv_usec;
	return (SUCCESS);
}

// int	main(void) {
// 	uint64_t	start;
// 	uint64_t	end;
// 	uint64_t	howlong = 1000000;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		get_useconds_time(&start);
// 		printf("test%d\n", i);
// 		// printf("%lu\n", start);
// 		safe_usleep(howlong);
// 		get_useconds_time(&end);
// 		// printf("%lu\n", end);
// 		printf("ideal %lu, real %lu\n", howlong, end - start);
// 	}
// }

// int	main(void)
// {
// 	int64_t	a = 616926112837;

// 	printf("%" PRId64 " %d %s\n", a, 10, MSG_DIE);
// 	return (0);
// }

// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return 1;
// 	printf("%lld\n", ft_ato64(av[1]));
// 	return 0;
// }
