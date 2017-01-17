/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/11 18:29:04 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <ctype.h>


typedef struct			s_elem
{
	char				**tetri;
	struct s_elem		*next;
}						t_element;

typedef	struct			s_list
{
	char				**tetri;
	struct s_elem		*first;
}						t_list;

void		init_list(t_list *list);
int			add_elem(t_list liste, char **tetri);
void		aff_list(llist list);
void		free_list(t_list *list);

#endif
