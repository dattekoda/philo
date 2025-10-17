/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:33:24 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 22:16:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

int64_t	ft_ato64(const char *s)
{
	bool		issigned;
	uint64_t	num;

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
	size_t	cal_size;

	if (count != 0 && SIZE_MAX / size < count)
		return (NULL);
	cal_size = count * size;
	cal = malloc(cal_size);
	if (!cal)
		return (NULL);
	memset(cal, 0, cal_size);
	return (cal);
}

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	while (*s1 && *s2 && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
// }
