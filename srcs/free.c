/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:19:19 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 21:21:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include <stdlib.h>
#include <pthread.h>

static void	safe_destroy(pthread_mutex_t *mutex)
{
	if (!mutex)
		return ;
	if (pthread_mutex_destroy(mutex))
		msg_function_err(ERR_MSG_DESTROY);
	free(mutex);
}

void	free_data(t_data *data)
{
	safe_destroy(data->data_mutex);
	safe_destroy(data->printf_mutex);
	safe_destroy(data->fork_mutex);
	safe_destroy(data->err_mutex);
}
