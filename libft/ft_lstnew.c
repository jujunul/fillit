/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:15:03 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/24 13:20:55 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*truc;

	if (!(truc = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		truc->content = NULL;
		truc->content_size = 0;
		truc->next = NULL;
	}
	else
	{
		if (!(truc->content = (t_list*)malloc(content_size)))
			return (NULL);
		ft_memcpy(truc->content, content, content_size);
		truc->content_size = content_size;
		truc->next = NULL;
	}
	return (truc);
}
