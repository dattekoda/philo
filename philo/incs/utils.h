/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/16 14:30:33 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"
# include "ft.h"
# include <stdint.h>
# include <stddef.h>

// free.c
void	free_data(t_data *data);
void	free_philo(t_philo *philo);

// utils.c
int		safe_printf(t_philo *philo, char *msg);
int		get_milliseconds_time(uint64_t *time);
int		safe_usleep(uint64_t time, t_data *data);
int		update_now_ms(t_data *data);

#endif