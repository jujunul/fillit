/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:25:25 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/30 19:44:42 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	take_out_of_map(t_elem *elem, t_env *env)
{
	int	x;
	int	y;

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

int		do_tetri_fit(t_elem *elem, t_env *env, int x, int y)
{
	int	t_x;
	int	t_y;
	int	x_first;
	int	y_first;

	t_y = 0;
	y_first = -1;
	while (t_y < 4)
	{
		t_x = 0;
		while (t_x < 4)
		{
			if (elem->tetri[t_y][t_x] == '#')
			{
				if (y_first == -1)
				{
					y_first = t_y;
					x_first = t_x;
				}
				else
				{
					if ((t_y - y_first + y >= 0
						&& t_y - y_first + y < env->len_map)
						&& (t_x - x_first + x >= 0
						&& t_x - x_first + x < env->len_map)
						&& (env->map[t_y - y_first + y][t_x - x_first + x] != '.'))
						return (1);
				}
			}
			t_x++;
		}
		t_y++;
	}
	return (0);
}

void	put_in_map(t_elem *elem, t_env *env, int x, int y)
{
	int	t_x;
	int	t_y;
	int	x_first;
	int	y_first;

	t_y = 0;
	y_first = -1;
	while (t_y < 4)
	{
		t_x = 0;
		while (t_x < 4)
		{
			if (elem->tetri[t_y][t_x] == '#')
			{
				if (y_first == -1)
				{
					y_first = t_y;
					x_first = t_x;
				}
				else
					env->map[t_y - y_first + y][t_x - x_first + x] = elem->letter;
			}
			t_x++;
		}
		t_y++;
	}
}

int		ft_algo(t_elem *elem, t_env *env)
{
	int	x;
	int	y;

	if (elem == NULL)
		return (0);
	y = 0;
	while (y < env->len_map)
	{
		x = 0;
		while (x < env->len_map)
		{
			if (env->map[y][x] == '.'
				&& do_tetri_fit(elem, env, x, y) == 0)
			{
				put_in_map(elem, env, x, y);
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
