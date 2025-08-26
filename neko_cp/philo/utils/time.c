#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>

struct timeval	interval(struct timeval a, struct timeval b);
static int64_t	get_ms(void);

int64_t	timeval2ms(struct timeval *t)
{
	return ((uint64_t)(t->tv_sec * 1000) + (uint64_t)(t->tv_usec / 1000));
}

// if error, return -1
int	msleep(uint64_t time)
{
	int64_t			end_time;
	int64_t			rem;
	__useconds_t	chunks_us;

	end_time = get_ms() + time;
	if (end_time == -1 + time)
		return (-1);
	while (1)
	{
		rem = end_time - get_ms();
		if (rem == end_time + 1)
			return (-1);
		if (rem <= 0)
			break ;
		if (rem > 20)
			chunks_us = (rem - 1) * 1000;
		else
			chunks_us = 100;
		if (usleep(chunks_us))
			return (-1);
	}
	return (0);
}

struct timeval	interval(struct timeval a, struct timeval b)
{
	struct timeval	ret;

	ret.tv_sec = a.tv_sec - b.tv_sec;
	ret.tv_usec = a.tv_usec - b.tv_usec;
	while (ret.tv_usec < 0)
	{
		ret.tv_sec--;
		ret.tv_usec += 1000000;
	}
	return (ret);
}

static int64_t	get_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (timeval2ms(&time));
}

// #include <stdio.h>
// int	main(void)
// {
// 	long	start;
// 	long	end;

// 	printf("set\treal\terror\n");
// 	for (int i = 1; i <= 1.0e4; i *= 5) {
// 		start = get_ms();
// 		if (msleep(i))
// 			return (1);
// 		end = get_ms();
// 		printf("%d\t%ld\t%ld\n", i, end - start, end - start - i);
// 	}
// 	return (0);
// }
