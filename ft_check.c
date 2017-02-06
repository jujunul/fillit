/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 03:19:42 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/06 03:19:44 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_checktetri(t_env *env)
{
	int		x;
	int		y;
	t_elem	*tmp;
	int		liaison;

	tmp = env->first;
	while (tmp)
	{
		y = -1;
		liaison = 0;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if (tmp->tetri[y][x] == '#')
				{
					((ft_x(x, y, tmp) + ft_y(x, y, tmp)) == 0) ? ft_puterror()
					: (liaison += (ft_x(x, y, tmp) + ft_y(x, y, tmp)));
				}
			}
		}
		(liaison < 6) ? ft_puterror() : (liaison = 0);
		tmp = tmp->next;
	}
}

int				ft_checkfile(char *av, t_env *env, t_elem *list)
{
	int			fd;
	char		*buf;
	int			ltetri;
	char		tmp;

	ltetri = 0;
	if (!(buf = ft_strnew(22)))
		return (0);
	if (!(fd = open(av, O_RDONLY)))
		ft_puterror();
	while (read(fd, buf, 21))
	{
		ft_isvalid(buf);
		ft_startparsing(buf, ltetri, env, list);
		ltetri++;
		tmp = buf[20];
		ft_bzero(buf, 21);
	}
	if (tmp == '\n')
		ft_puterror();
	if (!(ft_start_map(ltetri, env)))
		return (0);
	ft_checktetri(env);
	return (1);
}

int				ft_x(int x, int y, t_elem *tmp)
{
	int liaison;

	liaison = 0;
	if (x == 3)
	{
		if (tmp->tetri[y][x - 1] == '#')
			liaison++;
	}
	else if (x == 0)
	{
		if (tmp->tetri[y][x + 1] == '#')
			liaison++;
	}
	else
	{
		if (x < 3 && tmp->tetri[y][x + 1] == '#')
			liaison++;
		if (x > 0 && tmp->tetri[y][x - 1] == '#')
			liaison++;
	}
	return (liaison);
}

int				ft_y(int x, int y, t_elem *tmp)
{
	int liaison;

	liaison = 0;
	if (y == 3)
	{
		if (tmp->tetri[y - 1][x] == '#')
			liaison++;
	}
	else if (y == 0)
	{
		if (tmp->tetri[y + 1][x] == '#')
			liaison++;
	}
	else
	{
		if (tmp->tetri[y + 1][x] == '#')
			liaison++;
		if (tmp->tetri[y - 1][x] == '#')
			liaison++;
	}
	return (liaison);
}
