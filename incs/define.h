/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:54:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/26 16:19:33 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>

# define ERR -1
# define SUCCESS 0
# define FAILURE 1

# define DEFAULT_ARGC 5
# define OPTION_ARGC 6

typedef struct s_arg
{
	int			number_of_philosophers;
	int64_t		time_to_die;
	int64_t		time_to_eat;
	int64_t		time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_arg;

typedef struct s_data
{
	pthread_mutex_t	*data;
	t_arg			*arg;
}	t_data;

#endif