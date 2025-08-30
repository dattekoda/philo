/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:17:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/30 12:23:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "define.h"

int	init_arg(int argc, char **argv, t_arg *arg);
int	init_data(t_data *data, t_data *arg);
int	init_philo(t_philo **philo, t_data *data);

int	philospher(t_philo *philo);

#endif