#include "ft_func.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	bool			sign;

	num = 0;
	sign = false;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-');
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	return ((int)((-2 * sign + 1) * num));
}

// int	main(int ac, char **av) {
// 	if (ac == 1)
// 		return (1);
// 	printf("%d\n", ft_atoi(av[1]));
// }