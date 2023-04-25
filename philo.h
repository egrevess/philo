/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:10:41 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 18:33:34 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_struct	t_struct;

typedef struct s_thread
{
	pthread_t		thread;
	int				num;
	int				nb_eat;
	long int		time_last_meal;
	pthread_mutex_t *fork_right;
	pthread_mutex_t *fork_left;
	t_struct		*s;
}	t_thread;

typedef struct s_struct
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				enough_eating;
	int				index;
	long int		current_time;
	long int		start_time;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_check;
	t_thread 		*threads;
}	t_struct;

int			ft_atoi(const char *str, int *check);
int 		ft_check_argument(char **av);
int 		ft_check_not_dead(t_thread *philo);
void*		ft_routine(void* arg);
int			ft_free_mutex(t_struct *s);
void		ft_msg(char *msg,t_thread *philo);
long int	get_time();
int			ft_usleep(int time);
void		finish(int free, int mutex, int threads, t_struct *s);

#endif