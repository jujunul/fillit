/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:04:08 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:16:28 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if ((char)c == '\0')
	{
		i = ft_strlen((char*)s);
		return ((char*)(s + i));
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		else
			i++;
	}
	return (NULL);
}
