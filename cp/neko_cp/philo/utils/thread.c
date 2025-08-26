#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

// wrapper funcs
pthread_t	*thread_start(void *(*routine)(void *), void *args)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t));
	if (thread && pthread_create(thread, NULL, routine, args))
	{
		free(thread);
		thread = NULL;
	}
	return (thread);
}

int	thread_join(pthread_t *thread, void **thread_return)
{
	if (thread && pthread_join(*thread, thread_return))
		return (-1);
	free(thread);
	return (0);
}

pthread_mutex_t	*mutex_new(size_t size)
{
	pthread_mutex_t	*var;
	size_t	i;

	if (size != 0 && SIZE_MAX / size > sizeof(pthread_mutex_t))
		return (NULL);
	var = malloc(sizeof(pthread_mutex_t) * size);
	i = 0;
	while (var && i < size)
	{
		if (pthread_mutex_init(&var[i++], NULL))
		{
			while (i != 0)
				pthread_mutex_destroy(&var[--i]);
			free(var);
			var = NULL;
		}
	}
	return (var);
}

int	mutex_del(pthread_mutex_t *var)
{
	if (var && pthread_mutex_destroy(var))
		return (-1);
	free(var);
	return (0);
}
