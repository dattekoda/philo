/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:05:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/28 19:56:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include <string.h>

static int	validate_arg(int argc, t_arg *arg);

int	init_arg(int argc, char **argv, t_arg *arg)
{
	if (argc != DEFAULT_ARGC && argc != OPTION_ARGC)
		return (msg_usage(argv[0]), ERR);
	memset(arg, 0, sizeof(t_arg));
	arg->number_of_philosophers = (int)ft_ato64(argv[1]);
	arg->time_to_die = ft_ato64(argv[2]);
	arg->time_to_eat = ft_ato64(argv[3]);
	arg->time_to_sleep = ft_ato64(argv[4]);
	arg->number_of_times_each_philosopher_must_eat = -1;
	if (argc == OPTION_ARGC)
		arg->number_of_times_each_philosopher_must_eat = (int)ft_ato64(argv[5]);
	if (validate_arg(argc, arg))
		return (msg_err(ERR_MSG_FORMAT), ERR);
	return (SUCCESS);
}

static int	validate_arg(int argc, t_arg *arg)
{
	if (arg->number_of_philosophers < 1)
		return (ERR);
	if (arg->time_to_die < 1)
		return (ERR);
	if (arg->time_to_eat < 1)
		return (ERR);
	if (arg->time_to_sleep < 1)
		return (ERR);
	if (argc == OPTION_ARGC && arg->number_of_times_each_philosopher_must_eat < 1)
		return (ERR);
	return (0);
}

int	init_data(t_data *data, t_arg *arg)
{
	memset(data, 0, sizeof(t_data));
	data->arg = arg;
	if (pthread_mutex_init(data->mutex, NULL))
		return (msg_function_err(ERR_MSG_INIT),  ERR);
	data->fork = ft_calloc()
}
