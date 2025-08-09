/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:41:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/09 16:50:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc != NUM_NORMAL_ARG && argc != NUM_OPTIONAL_ARG)
		return (ft_putendl_err("Invalid number of arguments."), ERR);
	if (set_data(argc, argv, &data))
		return (ERR);
	if (philosopher(&data))
		return (free_data(&data), ERR);
	return (free_data(&data), SUCCESS);
}
