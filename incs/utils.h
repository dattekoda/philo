/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 21:18:45 by khanadat         ###   ########.fr       */
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

// utils.c
int		update_time_since_start(t_philo *philo, uint64_t *time);
int		safe_printf(t_philo *philo, char *msg);
int		get_milliseconds_time(uint64_t *time);
int		safe_usleep(uint64_t time, t_data *data);

// msg.c
void	msg_format_err(void);
void	msg_usage_err(const char *name);
void	msg_function_err(const char *func);

#endif