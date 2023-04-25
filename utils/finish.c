/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:31:01 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 18:51:18 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy_mutex(int mutex, t_struct *s)
{
	int	i;

	i = 0;
	if (mutex < 3)
	{
		pthread_mutex_destroy(s->mutex_print);
		free(s->mutex_print);
		pthread_mutex_destroy(s->mutex_check);
		free(s->mutex_check);
	}
	if (mutex == 3)
	{
		while (&s->forks[i])
		{
			pthread_mutex_destroy(&s->forks[i]);
			i++;
		}
		free(s->forks);
	}
}

void	finish(int free, int mutex, int threads,t_struct *s)
{
	if (!free)
		ft_free_mutex(s);
	if (!mutex)
		ft_destroy_mutex(mutex,s);
	if (!threads)
		ft_threads_join(s);
}