#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stddef.h>
# include <sys/time.h>
# include <stdint.h>

size_t			even_odd(size_t i, size_t len);
size_t			reverse_even_odd(size_t i, size_t len);

int				ft_strlen(const char *s);
long			ft_atol(const char *str);
int				ft_isdigit(int c);
int				ft_isnumber(const char *src, int issigned);
int				ft_isspace(int c);
char			*ft_strchr(const char *s, int c);

// thread.c
pthread_t		*thread_start(void *(*routine)(void *), void *args);
int				thread_join(pthread_t *thread, void **thread_return);
pthread_mutex_t	*mutex_new(size_t size);
int				mutex_del(pthread_mutex_t *var);

// time.c
int64_t			timeval2ms(struct timeval *t);
int				msleep(uint64_t time);

#endif