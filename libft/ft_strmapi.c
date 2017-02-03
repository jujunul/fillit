/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:20:20 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:36:48 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*new;

	if (s)
	{
		i = 0;
		len = ft_strlen((char*)s);
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i])
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
