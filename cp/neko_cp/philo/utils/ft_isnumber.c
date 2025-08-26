#include "utils.h"

int	ft_isnumber(const char *src, int issigned)
{
	if (issigned && (*src == '-' || *src == '+'))
		src++;
	if (!*src)
		returun (0);
	while (ft_isdigit(*src))
		src++;
	return (!*src);
}
