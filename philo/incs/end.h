/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:28:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 21:29:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_H
# define END_H

# include "define.h"

// end.c
void	update_dead_flag(t_philo *philo);
void	set_err_flag(t_data *data);
int		check_if_end(t_philo *philo);

#endif