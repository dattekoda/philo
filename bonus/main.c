/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:52:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/15 12:44:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include <string.h>
#include <stdlib.h>

int64_t	ft_ato64(const char *str)
{
	uint64_t	num;
	bool		issigned;

	issigned = false;
	num = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-');
		issigned = (*str++ == '-');
	while ('0' <= *str && *str <= '9')
		num += num * 10 + (*str++ - '0');
	return ((int64_t)((1 - 2 * issigned) * num));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;

	n = nmemb * size;
	if (size && n / size != nmemb)
		return (NULL);
	ptr = malloc(n);
	if (ptr)
		memset(ptr, 0, n);
	return (ptr);
}

int	validate_arg(int argc, char *argv[])
{
	if (argc != DEFAULT_ARGC && argc != OPTION_ARGC)
		return (ERR);
	if (ft_ato64(argv[1]) < 1 || ft_ato64(argv[2]) < 1 \
		|| ft_ato64(argv[3]) < 1 || ft_ato64(argv[4]) < 1)
		return (ERR);
	if (argc == OPTION_ARGC && ft_ato64(argv[5]) < 1)
		return (ERR);
	return (SUCCESS);
}

void	set_arg(int argc, char *argv[], t_arg *arg)
{
	arg->number_of_philosophers = (int)ft_ato64(argv[1]);
	arg->time_to_die = ft_ato64(argv[2]);
	arg->time_to_eat = ft_ato64(argv[3]);
	arg->time_to_sleep = ft_ato64(argv[4]);
	arg->number_of_times_each_philosopher_must_eat = NO_OPTION;
	if (argc == OPTION_ARGC)
		arg->number_of_times_each_philosopher_must_eat = (int)ft_ato64(argv[5]);
}

int	set_data(t_data **data, t_arg *arg)
{
	*data = ft_calloc(1, sizeof(t_data));
	data->
}

int	philosophers(t_arg *arg)
{
	t_data	*data;

}

int	main(int argc, char *argv[])
{
	t_arg	arg;

	if (validate_arg(argc, argv))
		return (1);
	set_arg(argc, argv, &arg);
	return (philosophers(&arg));
}
