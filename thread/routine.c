/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:11:46 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 18:02:03 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_eating(t_thread *philo)
{
	ft_msg("is eating", philo);
	philo->time_last_meal = get_time();
	ft_usleep(philo->s->time_to_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void* ft_routine(void* arg)
{
    t_thread *philo;

	philo = (t_thread*) arg;
	if (philo->num % 2 == 0)
		ft_usleep(philo->s->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(philo->fork_left);
		ft_msg("has taken a fork", philo);
		if (philo->s->nb_philo == 1)
		{
			ft_usleep(philo->s->time_to_die / 2);
			pthread_mutex_unlock(philo->fork_left);
			ft_msg("is dead", philo);
			return(1);
		}
		pthread_mutex_lock(philo->fork_right);
		ft_msg("has taken a fork", philo);
		if (ft_check_not_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			return(1);
		}
		ft_eating(philo);
		ft_msg("is sleeping", philo);
		ft_usleep(philo->s->time_to_sleep);
		ft_msg("is thinking", philo);
		
	}
	//printf("philo is dead");
	return (NULL);
}