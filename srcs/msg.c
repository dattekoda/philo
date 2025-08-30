/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:54:09 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/30 11:57:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include <unistd.h>

void	msg_err(const char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
}

void	msg_usage_err(const char *func)
{
	msg_err(ERR_MSG_INVALID);
	msg_err(ERR_MSG_USAGE);
	msg_err(func);
	msg_err(ERR_MSG_ARGUMENTS);
}

void	msg_function_err(const char *func)
{
	msg_err("Error: ");
	msg_err(func);
	msg_err(" failed\n");
}
