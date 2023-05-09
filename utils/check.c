/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:07:02 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/09 12:09:21 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_argument(char **av)
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

void	*ft_check_not_dead(void *arg)
{
	t_struct	*s;
	int			i;

	s = (t_struct *) arg;
	while (!s->dead)
	{
		i = -1;
		while (++i < s->nb_philo)
		{
			if (s->stop == s->nb_philo)
			{
				s->dead = 1;
				break ;
			}
			if (get_time() - s->threads[i].time_last_meal > s->time_to_die)
			{
				ft_msg("is dead", &s->threads[i]);
				s->dead = 1;
			}
			if (s->enough_eating == 1 && s->threads[i].nb_eat == s->limit_meal)
				s->stop++;
		}
	}
	return (NULL);
}
