/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:50:30 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/11 17:43:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

bool	is_err(t_data *data)
{
	bool	is_;

	pthread_mutex_lock(data->err_mutex);
	is_ = data->err_flag;
	pthread_mutex_unlock(data->err_mutex);
	return (is_);
}

bool	is_end(t_data *data)
{
	bool	is_;

	pthread_mutex_lock(data->end_mutex);
	is_ = data->end_flag;
	pthread_mutex_unlock(data->end_mutex);
	return (is_);
}

uint64_t	get_now_ms(t_data *data)
{
	uint64_t	now;

	pthread_mutex_lock(data->now_ms_mutex);
	now = data->now_ms;
	pthread_mutex_unlock(data->now_ms_mutex);
	return (now);
}
