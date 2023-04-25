/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:24:02 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/22 12:32:16 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo.h"

int	ft_atoi(const char *str, int *check)
{
	long int	i;
	long		nb;
	long int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1 * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] + (nb * 10) - 48;
		i++;
	}
	if (nb * neg > INT_MAX || nb * neg < INT_MIN || str[i] || i == 0)
		(*check) = 1;
	return (nb * neg);
}