/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:06:21 by alanteri          #+#    #+#             */
/*   Updated: 2017/02/03 17:32:24 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			do_tetri_fit(t_elem *elem, t_env *env)
{
	int		t_x;
	int		t_y;

	t_y = 0;
	env->y_first = -1;
	while (t_y < 4)
	{
		t_x = 0;
		while (t_x < 4)
		{
			if (elem->tetri[t_y][t_x] == '#')
			{
				if (env->y_first == -1)
					save_prev(env, t_y, t_x);
				else
				{
					if (tetri_is_not_in_condition(env, t_y, t_x) == 1)
						return (1);
				}
			}
			t_x++;
		}
		t_y++;
	}
	return (0);
}

void		put_in_map(t_elem *elem, t_env *env)
{
	int		t_x;
	int		t_y;

	t_y = 0;
	env->y_first = -1;
	while (t_y < 4)
	{
		t_x = 0;
		while (t_x < 4)
		{
			if (elem->tetri[t_y][t_x] == '#')
			{
				if (env->y_first == -1)
					save_prev(env, t_y, t_x);
				env->map[t_y - env->y_first + env->y]
				[t_x - env->x_first + env->x] = elem->letter;
			}
			t_x++;
		}
		t_y++;
	}
}

int			ft_algo(t_elem *elem, t_env *env)
{
	if (!(elem))
		return (0);
	env->y = 0;
	while (env->y < env->len_map)
	{
		env->x = 0;
		while (env->x < env->len_map)
		{
			if (env->map[env->y][env->x] == '.' && do_tetri_fit(elem, env) == 0)
			{
				put_in_map(elem, env);
				if (ft_algo(elem->next, env) == 0)
					return (0);
				else
					take_out_of_map(elem, env);
			}
			env->x++;
		}
		env->y++;
	}
	return (1);
}
