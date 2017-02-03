/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:40:59 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/21 19:32:00 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*tmp;

	tmp = (void *)s;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)tmp)[i] == ((unsigned char)c))
			return (tmp + i);
		i++;
	}
	return (NULL);
}
