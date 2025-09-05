/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:26:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/06 00:35:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdint.h>
# include <stddef.h>

// ft.c
int64_t	ft_ato64(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);

#endif