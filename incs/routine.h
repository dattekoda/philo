/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:28:51 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 06:02:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "define.h"

// eat.c
int		do_eat(t_philo *philo);
int		take_one_fork(t_philo *philo);

// routine.c
void	*routine(void *arg);
int		wait_until_all_threads_created(t_data *data);

#endif