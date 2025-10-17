/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:54:09 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 20:04:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include <unistd.h>

static void	msg_err(const char *msg);

void	msg_format_err(void)
{
	msg_err("Invalid format of arguments.\n" \
"all arguments should be number.\n" \
"number_of_philosophers > 0\n" \
"time_to_die > 1\n" \
"time_to_eat > 1\n" \
"time_to_sleep > 1\n" \
"[number_of_times_each_philosopher_must_eat] > 0\n");
}

void	msg_usage_err(const char *name)
{
	msg_err(ERR_MSG_INVALID);
	msg_err(ERR_MSG_USAGE);
	msg_err(name);
	msg_err(" number_of_philosophers" \
" time_to_die" \
" time_to_eat" \
" time_to_sleep" \
" [number_of_times_each_philosopher_must_eat]\n");
}

void	msg_function_err(const char *func)
{
	msg_err("Error: ");
	msg_err(func);
	msg_err(" failed\n");
}

static void	msg_err(const char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
}
