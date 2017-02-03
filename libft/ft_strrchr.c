/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:51:56 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:16:42 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (i == 0)
		return (NULL);
	if ((char)c == '\0')
		return ((char*)(s + i));
	while (--i >= 0)
	{
		if (s[i] == (char)c)
			return (((char*)(s + i)));
	}
	return (NULL);
}
