/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:09:43 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/08 18:01:55 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	int	start;
	int	current;

	start = get_time();
	current = get_time();
	while (current - start < time)
	{
		usleep (100);
		current = get_time();
	}
	return (0);
}
