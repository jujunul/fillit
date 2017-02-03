/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:06:25 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/24 12:51:29 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	int i;

	if (!s || !fd)
		return ;
	i = ft_strlen((char*)s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
