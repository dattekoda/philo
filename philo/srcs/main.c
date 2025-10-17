/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:17:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 05:59:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "msg.h"
#include "philo.h"

static int	validate_arg(int argc, char *argv[]);

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (validate_arg(argc, argv))
		return (FAILURE);
	if (init_arg(argc, argv, &arg))
		return (FAILURE);
	if (philosopher(&arg))
		return (FAILURE);
	return (SUCCESS);
}

static int	validate_arg(int argc, char *argv[])
{
	if (argc != DEFAULT_ARGC && argc != OPTION_ARGC)
		return (msg_usage_err(argv[0]), ERR);
	if (ft_ato64(argv[1]) < 1)
		return (msg_format_err(), ERR);
	if (ft_ato64(argv[2]) < 1)
		return (msg_format_err(), ERR);
	if (ft_ato64(argv[3]) < 1)
		return (msg_format_err(), ERR);
	if (ft_ato64(argv[4]) < 1)
		return (msg_format_err(), ERR);
	if (argc == OPTION_ARGC && ft_ato64(argv[5]) < 1)
		return (msg_format_err(), ERR);
	return (SUCCESS);
}
