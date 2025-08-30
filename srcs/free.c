/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:19:19 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/30 12:19:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"

void	safe_destroy(pthread_mutex_t *mutex)
{
	if (!mutex)
		return ;
	if (pthread_mutex_destroy(mutex))
	{
		msg_function_err(ERR_MSG_DESTROY);
		return ;
	}
	free(mutex);
}

void	free_data(t_data *data)
{
	if (data->fork_state)
		free(data->fork_state);
	safe_destroy(data->mutex);
	safe_destroy(data->printf_mutex);
	safe_destroy(data->fork_mutex);
}
