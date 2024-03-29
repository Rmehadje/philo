/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:27 by rmehadje          #+#    #+#             */
/*   Updated: 2024/02/04 20:28:49 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write (1, "wrong number of arguments", 25);
		return (1);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken the right fork\n");
		usleep(ft_atoi(argv[2]) * 100);
		printf("%d died", ft_atoi(argv[1]));
	}
	else
	{
		if (init_args(argv) == -1)
			printf("error\n");
	}
	return (0);
}
