/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/03 19:02:47 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <libft.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

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
	int					y_first;
	int					x_first;
	int					y;
	int					x;
	int					nbtetri;
}						t_env;

int						ft_algo(t_elem *elem, t_env *env);
void					put_in_map(t_elem *elem, t_env *env);
int						do_tetri_fit(t_elem *elem, t_env *env);
void					take_out_of_map(t_elem *elem, t_env *env);
void					save_prev(t_env *env, int t_y, int t_x);
int						tetri_is_not_in_condition(t_env *env, int t_y, int t_x);

#endif
