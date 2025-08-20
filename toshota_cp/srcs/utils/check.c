#include "utils.h"

void	*check_malloc(void *return_value)
{
	if (return_value == NULL)
		ft_putstr_fd("failed to malloc\n", STDERR_FILENO);
	return (return_value);
}
