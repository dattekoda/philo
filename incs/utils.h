/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:23:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/28 19:51:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>

int64_t	ft_ato64(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	msg_err(const char *msg);
void	msg_usage(const char *func);
void	msg_function_err(const char *func);

#endif