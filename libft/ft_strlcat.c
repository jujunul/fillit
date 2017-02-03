/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 18:36:14 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/22 16:51:34 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t len;
	size_t i;

	i = -1;
	while (src[++i])
		;
	len = i;
	i = -1;
	while (++i < size && dest[i])
		;
	len += ((i < size) ? i : size);
	if ((int)(size - ft_strlen(dest)) > 0)
		ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	return (len);
}
