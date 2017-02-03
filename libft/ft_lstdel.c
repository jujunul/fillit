/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:42:34 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/24 14:08:23 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*alst = NULL;
}
