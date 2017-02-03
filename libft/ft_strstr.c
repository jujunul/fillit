/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 21:35:33 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/19 10:41:41 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int size;
	int j;

	i = 0;
	size = 0;
	while (to_find[size])
		size++;
	if (size == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
			if (j++ == size - 1)
				return (str + i);
		i++;
	}
	return (0);
}
