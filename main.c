/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:36:51 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 18:50:48 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static void	ft_init_threads(t_struct *s, t_thread *thread, int i)
{
	thread->num = i + 1;
	thread->nb_eat = 0;
	if (i == s->nb_philo - 1)
		thread->fork_right = &s->forks[0];
	else
		thread->fork_right = &s->forks[i + 1];
	thread->fork_left = &s->forks[i];
	thread->s = s;

}

static	int ft_init_mutex(t_struct *s)
{
	int	i;

	i = 0;
	s->mutex_print = malloc(sizeof(*s->mutex_print));
	s->forks = malloc(sizeof(*s->forks) * s->nb_philo);
	s->mutex_check = malloc(sizeof(*s->mutex_check));
	if (!s->forks || !s->mutex_print || !s->mutex_check)
		return(1);
	pthread_mutex_init(s->mutex_print, NULL);
	pthread_mutex_init(s->mutex_check, NULL);
	if (!s->mutex_print || !s->mutex_check)
	{
		ft_finish(1, 2, NULL ,s); // 2 destroy print et check 
		return(1);
	}
	while(i < s->nb_philo)
	{
		pthread_mutex_init(&s->forks[i], NULL);
		if (!&s->forks[i])
		{
			ft_finish(1, 3, NULL ,s); // 3 destroy forks 
			return(1);
		}
		i++;
	}
	return (0);
}

static int	ft_init_par(char **av, t_struct *s)
{
	int result;
	s->nb_philo = ft_atoi(av[1], 0);
	if (s->nb_philo < 1)
		result = 1;
	s->time_to_die = ft_atoi(av[2], 0);
	if (s->time_to_die < 1)
		result = 1;
	s->time_to_eat = ft_atoi(av[3], 0);
	if (s->time_to_eat < 1)
		result = 1;
	s->time_to_sleep = ft_atoi(av[4], 0);
	if (s->time_to_sleep < 1)
		result = 1;
	if (result == 1)
	{
		write (2,"Error : negatif number\n", 24);
		return(1);
	}
	return (0);
}

static	int ft_init_routine(t_struct *s)
{
	int	i;

	i = 0;
	s->threads = malloc (sizeof(*s->threads) * s->nb_philo);
	if (!s->threads)
	{
		ft_finish(NULL, 3, NULL, s);
		return(1);
	}
	s->start_time = get_time();
	while (i < s->nb_philo)
	{
		ft_init_threads(s, &s->threads[i], i);
		if (!&s->threads[i])
			// que dois je faire 
		pthread_create(&s->threads[i].thread, 
			NULL, ft_routine, &s->threads[i]);
		if (!&s->threads[i])
		{
			ft_finish (NULL, 3, 1, s);
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int ac,char **av)
{
	t_struct	s;
	int	i;

	if (ac == 5)
	{
		if (ft_check_argument(av) == 0)
		{
			if(ft_init_par(av, &s) == 1);
				return(1);
			if(ft_init_mutex(&s) == 1)
				return(1);
			if(ft_init_routine(&s) == 1);
				return(1);
			i = 0;
			while (s.threads[i].num)
			{
				pthread_join(s.threads[i].thread, NULL);
				pthread_mutex_destroy(&s.forks[i]);
				i++;
			}
			pthread_mutex_destroy(s.mutex_print);
			pthread_mutex_destroy(s.mutex_check);
			ft_finish(3, NULL, NULL, &s);
		}
		else 
			write (2,"Error : not a number\n", 22);
	}
	else
		write (2,"Error : wrong number of arguments\n", 35);
	return (0);
}