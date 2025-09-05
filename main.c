/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:17:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 00:37:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (validate_arg(argc, argv))
		return (FAILURE);
	if (init_arg(argc, argv, &arg))
		return (FAILURE);
	if (philopher(&arg))
		return (FAILURE);
	return (SUCCESS);
}
