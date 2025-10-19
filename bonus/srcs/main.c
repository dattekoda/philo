/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:50:56 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/19 21:07:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "philo_err.h"
#include "ft.h"
#include "set.h"

static int	validate_arg(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_arg	arg;

	if (validate_arg(argc, argv))
		return (FAILURE);
	set_arg(argc, argv, &arg);
	// if (philo(&arg))
	// 	return (FAILURE);
	return (SUCCESS);
}

static int	validate_arg(int argc, char *argv[])
{
	if (argc != DEFAULT_ARGC && argc != OPTION_ARGC)
		return (err_usage(argv[0]), ERR);
	if (ft_ato64(argv[1]) < 1)
		return (err_format(), ERR);
	if (ft_ato64(argv[2]) < 1)
		return (err_format(), ERR);
	if (ft_ato64(argv[3]) < 1)
		return (err_format(), ERR);
	if (ft_ato64(argv[4]) < 1)
		return (err_format(), ERR);
	if (argc == OPTION_ARGC && ft_ato64(argv[5]) < 1)
		return (err_format(), ERR);
	return (SUCCESS);
}
