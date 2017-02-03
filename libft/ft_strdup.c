/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:50:07 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/21 11:40:11 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		len;
	char	*cp;

	len = ft_strlen((char*)s1);
	if (!(cp = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(cp, (char*)s1);
	return (cp);
}
