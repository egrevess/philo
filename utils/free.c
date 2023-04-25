/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:10:16 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/04/20 18:26:05 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_free_mutex(t_struct *s)
{
	// est ce que je peux faire comme ca ?
	if (s->mutex_print)
		free(s->mutex_print);
	if (s->forks)
		free(s->forks);
	if (s->mutex_check)
		free(s->mutex_check);
	return(0);
}