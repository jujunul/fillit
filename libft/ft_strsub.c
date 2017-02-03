/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:16:22 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:49:40 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			j;

	i = (size_t)start;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s)
	{
		while (j < len)
		{
			new[j] = s[i];
			i++;
			j++;
		}
		new[j] = '\0';
	}
	return (new);
}
