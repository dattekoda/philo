/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:54:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/08/28 19:50:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

# define ERR -1
# define SUCCESS 0
# define FAILURE 1

# define DEFAULT_ARGC 5
# define OPTION_ARGC 6

# define ERR_MSG_USAGE "Usage: "
# define ERR_MSG_INVALID "Invalid number of arguments.\n"
# define ERR_MSG_ARGUMENTS " number_of_philosophers" \
" time_to_die" \
" time_to_eat" \
" time_to_sleep" \
" [number_of_times_each_philosopher_must_eat]\n"
# define ERR_MSG_FORMAT "Invalid format of arguments.\n" \
"number_of_philosophers > 0\n" \
"time_to_die > 1\n" \
"time_to_eat > 1\n" \
"time_to_sleep > 1\n" \
"[number_of_times_each_philosopher_must_eat] > 0\n"
# define ERR_MSG_INIT "pthread_mutex_init"
# define ERR_MSG_MALLOC "malloc"

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
	bool			*fork;
	pthread_mutex_t	*mutex;
	t_arg			*arg;
}	t_data;

#endif