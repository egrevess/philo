/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:31:01 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/09 14:33:46 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_destroy_mutex(int index_mutex, int mutex, t_struct *s)
{
	int	i;

	i = 0;
	if (mutex >= 1)
	{
		pthread_mutex_destroy(&s->mutex_print);
		pthread_mutex_destroy(&s->mutex_check);
		pthread_mutex_destroy(&s->mutex_dead);
		if (mutex > 1)
		{
			while (i <= index_mutex)
			{
				pthread_mutex_destroy(&s->forks[i]);
				i++;
			}
			free(s->forks);
		}
	}
}

static void	ft_threads_join(int index, int threads, t_struct *s)
{
	int	i;

	i = 0;
	if (threads >= 1)
	{
		while (i <= index)
		{
			pthread_join(s->threads[i].thread, NULL);
			i++;
		}
		free(s->threads);
	}
}

int	ft_finish(int idx_mutex, int idx_threads, int threads, t_struct *s)
{
	if (threads != 0)
		ft_threads_join(idx_threads, threads, s);
	if (s->mutex != 0)
		ft_destroy_mutex(idx_mutex, s->mutex, s);
	return (1);
}
