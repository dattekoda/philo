#include "utils.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == c)
			return ((char *)(--s));
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(int c, char **v)
// {
// 	if (c != 3)
// 		return 1;
// 	printf("%s\n", strchr(v[1], v[2][0]));
// 	printf("%s\n", ft_strchr(v[1], v[2][0]));
// }