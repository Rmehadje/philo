/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:13 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/03 19:17:58 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		init_philos(t_data *data)
{
	int		i;

	final_init(data);
	init_forks(data);
	i = 0;
	while (i < data->phils[0].num_of_phils)
	{
		data->phils[i].id = i + 1;
		data->phils[i].meals_eaten = 0;
		data->phils[i].eating = 0;
		data->phils[i].start = ft_real_time();
		data->phils[i].last_meal = ft_real_time();
		data->phils[i].meal_lock = &data->meal_lock;
		data->phils[i].write_lock = &data->write_lock;
		data->phils[i].dead_lock = &data->dead_lock;
		data->phils[i].dead = &data->dead;
		i++;
	}
	data->phils[0].left_f = &data->forks[0];
	data->phils[0].right_f = &data->forks[data->phils[0].num_of_phils - 1];
	i = 1;
	while (i < data->phils[0].num_of_phils)
	{
		data->phils[i].left_f = &data->forks[i];
		data->phils[i].right_f = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int		init_forks(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int		init_args(char **argv)
{
	int	i;
	t_data	*data;

	data = malloc(sizeof(t_data *));
	if (!data)
		return (-1);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data->phils[i].num_of_phils = ft_atoi(argv[1]);
		data->phils[i].time_before_death = ft_atoi(argv[2]);
		data->phils[i].time_to_eat = ft_atoi(argv[3]);
		data->phils[i].time_to_sleep = ft_atoi(argv[4]);
		data->phils[i].data = data;
		if (argv[5])
			data->phils[i].times_to_eat = ft_atoi(argv[5]);
		else
			data->phils[i].times_to_eat = -1;
		i++;
	}
	init_philos(data);
	init_threads(data);
	return (0);
}

int		init_threads(t_data	*data)
{
	int i;
	int	f;

	f = 0;
	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		data->phils[i].start = ft_real_time();
		data->phils[i].last_meal = ft_real_time();
		data->phils[i].ttd = data->phils[i].time_before_death;
		i++;
	}
	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		if (pthread_create(&(data->thread[i]), NULL, &munching, &data->phils[i]) == 1)
			return (0);
		i++;
	}
	if (death_checker(data) == 1)
		pthread_mutex_unlock(&data->write_lock);
	i = 0;
	while (i <data->phils[i].num_of_phils)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	destroy_all(data);
	return (0);
}

void	destroy_all(t_data	*data)
{
	int i;

	i = 0;
	while (i < data->phils[i].num_of_phils)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->phils[i].tmp);
		pthread_mutex_destroy(&data->phils[i].tmp2);
		pthread_mutex_destroy(&data->phils[i].tmp3);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
}

int	final_init(t_data	*data)
{
	data->isdead = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	return (0);
}
