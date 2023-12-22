/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:14:37 by rmehadje          #+#    #+#             */
/*   Updated: 2023/12/22 19:57:54 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct			s_philosophers
{
	int						nphilo;
	int						time_of_death;
	int						time_to_eat;
	int						start_time;
	int						time_to_sleep;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	int						eating;


}							t_philosophers;

typedef struct			s_data
{
	int					dead_f;
	pthread_mutex_t	;
	t_philosophers		*philosophers;
}							t_data;










#endif