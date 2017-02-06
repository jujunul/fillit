/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:06:21 by alanteri          #+#    #+#             */
/*   Updated: 2017/02/06 01:13:51 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			do_tetri_fit(t_elem *elem, t_env *env, int y, int x)
{
	env->t_y = 0;
	env->y_first = -1;
	while (env->t_y < 4)
	{
		env->t_x = 0;
		while (env->t_x < 4)
		{
			if (elem->tetri[env->t_y][env->t_x] == '#')
			{
				if (env->y_first == -1)
					save_prev(env, env->t_y, env->t_x);
				else
				{
					if (tetri_is_not_in_condition(env, y, x) == 1)
						return (1);
				}
			}
			env->t_x++;
		}
		env->t_y++;
	}
	return (0);
}

void		put_in_map(t_elem *elem, t_env *env, int y, int x)
{
	env->t_y = 0;
	env->y_first = -1;
	while (env->t_y < 4)
	{
		env->t_x = 0;
		while (env->t_x < 4)
		{
			if (elem->tetri[env->t_y][env->t_x] == '#')
			{
				if (env->y_first == -1)
				{
					save_prev(env, env->t_y, env->t_x);
				}
				env->map[env->t_y - env->y_first + y]
				[env->t_x - env->x_first + x] = elem->letter + 65;
			}
			env->t_x++;
		}
		env->t_y++;
	}
}

int			ft_algo(t_elem *elem, t_env *env)
{
	int x;
	int y;

	if (!(elem))
		return (0);
	y = 0;
	while (y < env->len_map)
	{
		x = 0;
		while (x < env->len_map)
		{
			if (env->map[y][x] == '.' && do_tetri_fit(elem, env, y, x) == 0)
			{
				put_in_map(elem, env, y, x);
				if (ft_algo(elem->next, env) == 0)
					return (0);
				else
					take_out_of_map(elem, env);
			}
			x++;
		}
		y++;
	}
	return (1);
}
