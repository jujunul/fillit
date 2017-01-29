/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/29 18:21:45 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct			s_elem
{
	char				**tetri;
	char				ltetri;
	struct s_elem		*next;
}						t_elem;

typedef	struct			s_env
{
	struct s_elem		*first;
}						t_env;

size_t		ft_strlen(char *str);
void		init_list(t_list *list);
void		aff_list(t_list list);
void		free_list(t_list *list);

#endif
