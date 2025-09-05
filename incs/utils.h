/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 22:26:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"
# include <stdint.h>
# include <stddef.h>

// end.c
int		update_dead_flag(t_philo *philo);
void	set_err_flag(t_data *data);

// free.c
void	free_data(t_data *data);

// ft.c
int64_t	ft_ato64(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);

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