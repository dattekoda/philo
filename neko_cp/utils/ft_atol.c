#include "utils.h"

long	ft_atol(const char *str)
{
	char			sign;
	unsigned long	num;

	num = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-');
	while (ft_isdigit(*str))
		num = 10 * num + (*str++ - '0');
	return ((long)((1 - 2 * sign) * num));
}
