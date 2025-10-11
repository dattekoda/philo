/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:50:30 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/11 17:03:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

bool	is_err(t_data *data)
{
	bool	is_err;

	pthread_mutex_lock(data->err_mutex);
	is_err = data->err_flag;
	pthread_mutex_unlock(data->err_mutex);
	return (is_err);
}

bool	is_end(t_data *data)
{
	bool	is_end;

	pthread_mutex_lock(data->end_mutex);
	is_end = data->end_flag;
	pthread_mutex_unlock(data->end_mutex);
	return (is_end);
}
