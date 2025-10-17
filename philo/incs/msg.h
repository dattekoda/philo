/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 05:55:38 by khanadat          #+#    #+#             */
/*   Updated: 2025/09/07 05:56:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

// msg.c
void	msg_format_err(void);
void	msg_usage_err(const char *name);
void	msg_function_err(const char *func);

#endif