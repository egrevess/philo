/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:10:41 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/09 12:14:04 by emmagrevess      ###   ########.fr       */
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
# include <stdatomic.h>

typedef struct s_struct	t_struct;

typedef struct s_thread
{
	pthread_t		thread;
	int				num;
	atomic_int		nb_eat;
	atomic_int		limit;
	atomic_llong	time_last_meal;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_struct		*s;
}					t_thread;

typedef struct s_struct
{
	int				nb_philo;
	atomic_int		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				enough_eating;
	int				limit_meal;
	int				index;
	atomic_int		mutex;
	atomic_int		stop;
	atomic_int		dead;
	atomic_llong	current_time;
	long int		start_time;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_check;
	pthread_mutex_t	mutex_dead;
	t_thread		*threads;
	pthread_t		threads_dead;
}					t_struct;

int			ft_atoi(const char *str, int *check);
int			ft_check_argument(char **av);
void		*ft_check_not_dead(void *arg);
void		*ft_routine(void *arg);
void		ft_msg(char *msg, t_thread *philo);
long int	get_time(void);
int			ft_usleep(int time);
int			ft_finish(int idx_mutex, int idx_threads, int threads, t_struct *s);

#endif