/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:17:59 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:15:39 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	i = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dst;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (dest2[i] == (unsigned char)c)
			return (&dest2[i + 1]);
		i++;
	}
	return (NULL);
}
