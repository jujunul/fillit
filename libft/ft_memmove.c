/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:37:23 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/21 20:09:10 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst > src)
	{
		i = (int)(len - 1);
		while (i >= 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < ((int)len))
		{
			((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
