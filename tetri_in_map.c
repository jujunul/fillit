/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_in_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:15:33 by alanteri          #+#    #+#             */
/*   Updated: 2017/02/03 17:35:59 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		take_out_of_map(t_elem *elem, t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->len_map)
	{
		x = 0;
		while (x < env->len_map)
		{
			if (env->map[y][x] == elem->letter)
				env->map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void		save_prev(t_env *env, int t_y, int t_x)
{
	env->y_first = t_y;
	env->x_first = t_x;
}

int			tetri_is_not_in_condition(t_env *env, int t_y, int t_x)
{
	if ((t_y - env->y_first + env->y >= 0
	&& t_y - env->y_first + env->y < env->len_map)
	&& (t_x - env->x_first + env->x >= 0
	&& t_x - env->x_first + env->x < env->len_map)
	&& (env->map[t_y - env->y_first + env->y]
		[t_x - env->x_first + env->x] != '.'))
		return (1);
	return (0);
}
