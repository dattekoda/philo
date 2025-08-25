#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stddef.h>
# include <sys/time.h>

size_t		even_odd(size_t i, size_t len);
size_t		reverse_even_odd(size_t i, size_t len);

int			ft_strlen(const char *s);
long		ft_atol(const char *str);
int			ft_isdigit(int c);
int			ft_isnumber(const char *src, int issigned);
int			ft_isspace(int c);
char		*ft_strchr(const char *s, int c);

#endif