/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:56:46 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/16 14:43:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "define.h"

bool		is_err(t_data *data);
bool		is_end(t_data *data);
uint64_t	get_now_ms(t_data *data);
uint64_t	get_start_ms(t_data *data);

void		update_ltte(t_philo *philo, uint64_t now_ms);
uint64_t	get_ltte(t_philo *philo);
void		update_eat_count(t_philo *philo);
int			get_eat_count(t_philo *philo);

#endif