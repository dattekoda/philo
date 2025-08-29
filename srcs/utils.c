/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:22:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/28 19:55:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "define.h"
#include <string.h>
#include <unistd.h>
#include <limits.h>

int64_t	ft_ato64(const char *s)
{
	uint64_t	num;
	char		issigned;

	num = 0;
	issigned = 0;
	while (*s == ' ' || ('\r' <= *s && *s <= '\t'))
		s++;
	if (*s == '-' || *s == '+')
		issigned = (*s++ == '-');
	while ('0' <= *s && *s <= '9')
		num = num * 10 + (*s++ - '0');
	return ((int64_t)((1 - 2 * issigned) * num));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if (count != 0 && SIZE_MAX / size < count)
		return (NULL);
	cal = malloc(count * size);
	if (!cal)
		return (NULL);
	memset(cal, 0, count * size);
	return (cal);
}

void	msg_err(const char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
}

void	msg_usage(const char *func)
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

// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return 1;
// 	printf("%lld\n", ft_ato64(av[1]));
// 	return 0;
// }
