/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:24:04 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/24 17:02:19 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *truc;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if (!(truc = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	truc = f(lst);
	if (lst->next != NULL)
		lst = lst->next;
	else
		return (truc);
	tmp = f(lst);
	truc->next = tmp;
	while (lst != NULL)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		tmp->next = new;
		lst = lst->next;
	}
	return (truc);
}
