#include "utils.h"

size_t	ft_strlen(const char *s)
{
	const char	*_s;

	_s = s;
	while (*_s)
		_s++;
	return ((size_t)(_s - s));
}
