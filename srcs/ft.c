/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:48:24 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/18 16:04:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putendl_err(char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	write(STDERR_FILENO, str, str_len);
	write(STDERR_FILENO, "\n", 1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;
	size_t	cal_size;

	if (nmemb > SIZE_MAX / nmemb)
		return (NULL);
	cal_size = size * nmemb;
	cal = (void *)malloc(cal_size);
	if (!cal)
		return (NULL);
	memset(cal, 0, cal_size);
	return (cal);
}

// int	main(void)
// {
// 	int	a = 10;
// 	int	b = 90;

// 	ft_swap(&a, &b);
// 	printf("a: %d, b: %d\n", a, b);
// 	return (0);
// }
