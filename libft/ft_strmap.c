/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:38:18 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:35:21 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t		len;
	char		*new;
	int			i;

	if (s)
	{
		len = ft_strlen((char*)s);
		if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
