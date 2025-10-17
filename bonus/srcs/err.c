/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:01:34 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 22:14:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "define.h"

static void	putstr_err(const char *str);

void	err_format(void)
{
	putstr_err(ERR_MSG_FORMAT);
	putstr_err("all arguments should be number.\n" \
"number_of_philosophers > 0\n" \
"time_to_die > 1\n" \
"time_to_eat > 1\n" \
"time_to_sleep > 1\n" \
"[number_of_times_each_philosopher_must_eat] > 0\n");
}

void	err_usage(const char *name)
{
	putstr_err(ERR_MSG_INVALID);
	putstr_err(ERR_MSG_USAGE);
	putstr_err(name);
	putstr_err(NOP);
	putstr_err(TTD);
	putstr_err(TTE);
	putstr_err(TTS);
	putstr_err(NOTEPME);
	write(STDERR_FILENO, "\n", 1);
}

static void	putstr_err(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(STDERR_FILENO, str, len);
}
