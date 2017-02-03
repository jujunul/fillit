/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:12:03 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:08:43 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	long int	i;
	long int	nbr;
	int			negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] < 14 && str[i] > 6) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (negative ? -nbr : nbr);
}
