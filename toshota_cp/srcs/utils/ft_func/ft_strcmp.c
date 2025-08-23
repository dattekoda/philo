#include "ft_func.h"
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

// #include <stdio.h>
// #include <string.h>
// int	main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	printf("%d\n", ft_strcmp(argv[1], argv[2]));
// 	printf("%d\n", strcmp(argv[1], argv[2]));
// 	return (0);
// }
