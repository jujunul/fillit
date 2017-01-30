/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/30 19:42:36 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct			s_elem
{
	char				**tetri;
	int					letter;
	struct s_elem		*next;
}						t_elem;

typedef	struct			s_env
{
	struct s_elem		*first;
	char				**map;
	int					len_map;
}						t_env;

int						ft_algo(t_elem *elem, t_env *env);
void					put_in_map(t_elem *elem, t_env *env, int x, int y);
int						do_tetri_fit(t_elem *elem, t_env *env, int x, int y);
void					take_out_of_map(t_elem *elem, t_env *env);

#endif
