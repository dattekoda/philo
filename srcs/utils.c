/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:22:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/04 22:43:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "define.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

int64_t	ft_ato64(const char *s)
{
	uint64_t	num;
	char		issigned;

	num = 0;
	issigned = 0;
	while (*s == ' ' || ('\r' <= *s && *s <= '\t'))
		s++;
	if (*s == '-' || *s == '+')
		issigned = (*s++ == '-');
	while ('0' <= *s && *s <= '9')
		num = num * 10 + (*s++ - '0');
	return ((int64_t)((1 - 2 * issigned) * num));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if (count != 0 && SIZE_MAX / size < count)
		return (NULL);
	cal = malloc(count * size);
	if (!cal)
		return (NULL);
	memset(cal, 0, count * size);
	return (cal);
}

int	safe_printf(t_philo *philo, char *msg)
{
	if (pthread_mutex_lock(philo->data->printf_mutex))
		return (msg_function_err(ERR_MSG_LOCK), ERR);
	if (printf("%" PRId64 " %d %s\n", philo->data->now_ms, philo->idx, msg) < 0)
		return (msg_function_err(ERR_MSG_PRINTF), \
		pthread_mutex_unlock(philo->data->printf_mutex), ERR);
	if (pthread_mutex_unlock(philo->data->printf_mutex))
		return (msg_function_err(ERR_MSG_UNLOCK), ERR);
	return (SUCCESS);
}

// success 0 error -1
// set time gettimeofday got
int	get_useconds_time(uint64_t *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ERR);
	*time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (SUCCESS);
}

// success 0 error -1
int	safe_usleep(uint64_t time)
{
	struct timeval	tv;
	uint64_t		start;
	uint64_t		now;

	if (get_useconds_time(&start))
		return (ERR);
	now = start;
	while (now < start + time)
	{
		if (usleep(100) || get_useconds_time(&now))
			return (ERR);
	}
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
