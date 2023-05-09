/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:36:51 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/09 12:15:36 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_threads(t_struct *s, t_thread *thread, int i)
{
	thread->num = i + 1;
	thread->nb_eat = 0;
	thread->time_last_meal = s->start_time;
	if (i == s->nb_philo - 1)
		thread->fork_right = &s->forks[0];
	else
		thread->fork_right = &s->forks[i + 1];
	thread->fork_left = &s->forks[i];
	thread->s = s;
}

static int	ft_init_mutex(t_struct *s)
{
	int	i;

	i = 0;
	s->mutex = 1;
	pthread_mutex_init(&s->mutex_print, NULL);
	pthread_mutex_init(&s->mutex_check, NULL);
	pthread_mutex_init(&s->mutex_dead, NULL);
	if (pthread_mutex_init(&s->mutex_print, NULL)
		|| pthread_mutex_init(&s->mutex_check, NULL)
		|| pthread_mutex_init(&s->mutex_dead, NULL))
		return (ft_finish(0, 0, 0, s));
	s->forks = malloc(sizeof(*s->forks) * s->nb_philo);
	if (!s->forks)
		return (ft_finish(0, 0, 0, s));
	s->mutex = 2;
	while (i < s->nb_philo)
	{
		pthread_mutex_init(&s->forks[i], NULL);
		if (!&s->forks[i])
			return (ft_finish(s->nb_philo - 1, 0, 0, s));
		i++;
	}
	return (0);
}

static int	ft_init_par(char **av, t_struct *s)
{
	int	result;

	result = 0;
	s->dead = 0;
	s->stop = 0;
	s->nb_philo = ft_atoi(av[1], 0);
	s->time_to_die = ft_atoi(av[2], 0);
	s->time_to_eat = ft_atoi(av[3], 0);
	s->time_to_sleep = ft_atoi(av[4], 0);
	if (s->enough_eating == 1)
	{
		s->limit_meal = ft_atoi(av[5], 0);
		if (s->limit_meal < 1)
			result = 1;
	}
	if (s->nb_philo < 1 || s->time_to_die < 1
		|| s->time_to_eat < 1 || s->time_to_sleep < 1
		|| result == 1)
	{
		write (2, "Error : wrong number\n", 22);
		return (1);
	}
	return (0);
}

static int	ft_init_routine(t_struct *s)
{
	int	i;

	i = 0;
	s->threads = malloc (sizeof(*s->threads) * s->nb_philo);
	if (!s->threads)
	{
		ft_finish(s->nb_philo - 1, 0, 0, s);
		return (1);
	}
	s->start_time = get_time();
	while (i < s->nb_philo)
	{
		ft_init_threads(s, &s->threads[i], i);
		pthread_create(&s->threads[i].thread,
			NULL, ft_routine, &s->threads[i]);
		if (!&s->threads[i])
		{
			ft_finish (s->nb_philo -1, i, 1, s);
			return (1);
		}
		i++;
	}
	pthread_create(&s->threads_dead,
		NULL, ft_check_not_dead, s);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	s;

	s.enough_eating = 0;
	if (ac == 5 || ac == 6)
	{
		if (ac == 6)
			s.enough_eating = 1;
		if (ft_check_argument(av) == 0)
		{
			if (ft_init_par(av, &s) == 1)
				return (1);
			if (ft_init_mutex(&s) == 1)
				return (1);
			s.mutex = 2;
			if (ft_init_routine(&s) == 1)
				return (1);
			ft_finish(s.nb_philo - 1, s.nb_philo - 1, 2, &s);
		}
		else
			write (2, "Error : not a number\n", 22);
	}
	else
		write (2, "Error : wrong number of arguments\n", 35);
	return (0);
}
