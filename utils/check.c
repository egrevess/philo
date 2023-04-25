/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:07:02 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/21 11:10:43 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo.h"

int ft_check_argument(char **av)
{
	int	check;
	int	i;

	check = 0;
	i = 1;
	while (av[i])
	{
		ft_atoi(av[i], &check);
		if (check == 1)
			return (1);
		i++;
	}
	return (0);
}

int ft_check_not_dead(t_thread *philo)
{
	pthread_mutex_lock(philo->s->mutex_check);
	if (philo->nb_eat == 0)
	{
		if (get_time() - philo->s->start_time > philo->s->time_to_die)
		{
			printf("test");
			ft_msg("is dead", philo);
			return(1) ;
		}
	}
	else if (philo->nb_eat != 0)
	{
		if (get_time() - philo->time_last_meal > philo->s->time_to_die)
		{
			ft_msg("is dead", philo);
			return (1);
		}
	}
	pthread_mutex_unlock(philo->s->mutex_check);
	return(0);
}