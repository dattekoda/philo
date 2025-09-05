/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:33:24 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/05 15:40:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
