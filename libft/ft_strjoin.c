/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:32:37 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 18:52:15 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	long int	len;
	char		*new;
	long int	i;
	long int	j;

	if (s1 && s2)
	{
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		j = 0;
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (s1[i])
			new[j++] = s1[i++];
		i = 0;
		while (s2[i])
			new[j++] = s2[i++];
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}
