/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:17:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 21:29:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "define.h"

// init.c
int		validate_arg(int argc, char *argv[]);
int		init_arg(int argc, char **argv, t_arg *arg);
int		init_data(t_data *data, t_arg *arg);
int		init_philo(t_philo **philo, t_data *data, t_arg *arg);

// philosopher.c
int		philosopher(t_arg *arg);

// routine.c
void	*routine(void *arg);

#endif