#include "ft_func.h"

size_t	ft_strlen(const char *str)
{
	const char	*_str;

	_str = str;
	while (*_str)
		_str++;
	return ((size_t)(_str - str));
}