/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:41:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/19 12:23:33 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_mutex			mutex;

	if (argc != NUM_NORMAL_ARG && argc != NUM_OPTIONAL_ARG)
		return (ft_putendl_err("Invalid number of arguments."), FAILURE);
	if (set_data(argc, argv, &data))
		return (FAILURE);
	if (set_mutex(&data, &mutex))
		return (FAILURE);
	if (philosopher(&data, &mutex))
		return (free_philo(&data, &mutex), FAILURE);
	return (free_philo(&data, &mutex), SUCCESS);
}
