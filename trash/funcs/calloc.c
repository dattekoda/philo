#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;
	size_t	cal_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	cal_size = size * nmemb;
	cal = (void *)malloc(cal_size);
	if (!cal)
		return (NULL);
	memset(cal, 0, cal_size);
	return (cal);
}

int	main(void)
{
	char *str = calloc(0, 0);
	char	*ft = ft_calloc(0, 0);

	if (str)
		printf("not null\n");
	if (ft)
		printf("ft\n");
	if (*ft)
		printf("*ft\n");
	return (0);
}
