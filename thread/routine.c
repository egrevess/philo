/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:11:46 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/09 15:39:36 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_eating(t_thread *philo)
{
	ft_msg("is eating", philo);
	pthread_mutex_lock(&philo->s->mutex_check);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->s->mutex_check);
	ft_usleep(philo->s->time_to_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	*ft_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *) arg;
	if (philo->num % 2 == 0)
		ft_usleep(philo->s->time_to_eat / 2);
	while (!philo->s->dead)
	{
		pthread_mutex_lock(philo->fork_left);
		ft_msg("has taken a fork", philo);
		if (philo->s->nb_philo == 1)
		{
			pthread_mutex_unlock(philo->fork_left);
			return ((void *) 1);
		}
		pthread_mutex_lock(philo->fork_right);
		ft_msg("has taken a fork", philo);
		ft_eating(philo);
		ft_msg("is sleeping", philo);
		ft_usleep(philo->s->time_to_sleep);
		ft_msg("is thinking", philo);
	}
	return (NULL);
}
