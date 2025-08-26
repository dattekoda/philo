#include <stddef.h>

size_t	even_odd(size_t i, size_t len)
{
	size_t	c;

	c = len / 2 + len % 2;
	if (c <= i)
		return ((i - c) * 2 + 1);
	else
		return (i * 2);
}

size_t	reverse_even_odd(size_t i, size_t len)
{
	if (i % 2)
		return (i / 2 + len % 2 + len / 2);
	return (i / 2);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	size_t	len = (size_t)atoi(argv[1]);
// 	for (size_t i = 0; i < len; i++) {
// 		printf("i =\t%zd:\neven_odd:\t%zd\nreverse:\t%zd\n", \
// 		i, even_odd(i, len), reverse_even_odd(even_odd(i, len), len));
// 	}
// }