/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:13 by rmehadje          #+#    #+#             */
/*   Updated: 2023/11/03 15:38:20 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_data	*data)
{
	int	i;

	i = data->nphilo;
	while (i >= 0)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->)))
}	