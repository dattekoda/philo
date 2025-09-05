/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 00:29:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"
# include "ft.h"
# include <stdint.h>
# include <stddef.h>

// end.c
int		update_dead_flag(t_philo *philo);
void	set_err_flag(t_data *data);
int		check_if_end(t_philo *philo);

// free.c
void	free_data(t_data *data);

// utils.c
int		update_time_since_start(t_philo *philo, uint64_t *time);
int		safe_printf(t_philo *philo, char *msg);
int		get_milliseconds_time(uint64_t *time);
int	    safe_usleep(uint64_t time);

// msg.c
void	msg_err(const char *msg);
void	msg_usage_err(const char *func);
void	msg_function_err(const char *func);

#endif