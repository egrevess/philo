/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:28:59 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 17:39:39 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_msg(char *msg, t_thread *philo)
{
	pthread_mutex_lock(philo->s->mutex_print);
	philo->s->current_time = get_time() - philo->s->start_time;
	printf("%ld %d %s\n", philo->s->current_time, philo->num, msg);
	pthread_mutex_unlock(philo->s->mutex_print);
}