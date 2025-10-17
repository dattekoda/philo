/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:52:38 by khanadat          #+#    #+#             */
/*   Updated: 2025/10/17 22:13:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdint.h>

# define ERR -1
# define SUCCESS 0
# define FAILURE 1

# define DEFAULT_ARGC 5
# define OPTION_ARGC 6
# define NO_OPTION -1
# define MS_TO_US 1000
# define SHORT_TIME 100
# define PER_PHILO_NUM 5 // monitors check this number of philo in each thread.

# define ERR_MSG_FORMAT "Invalid format of arguments.\n"
# define ERR_MSG_INVALID "Invalid number of arguments.\n"
# define ERR_MSG_USAGE "Usage: "
# define NOP " number_of_philosophers"
# define TTD " time_to_die"
# define TTE " time_to_eat"
# define TTS " time_to_sleep"
# define NOTEPME " [number_of_times_each_philosopher_must_eat]"

typedef struct s_arg
{
	int			number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_arg;

#endif