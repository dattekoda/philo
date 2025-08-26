#ifndef FT_FUNC_H
# define FT_FUNC_H

# include "define.h"

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif