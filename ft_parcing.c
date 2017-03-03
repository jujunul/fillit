/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 03:19:59 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/06 03:20:04 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_isvalid(char *buf)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			ft_puterror();
		if (buf[i] == '#')
			nb++;
		if (buf[i] == '\n' &&
			(i != 4 && i != 9 && i != 14 && i != 19 && i != 20))
			ft_puterror();
		i++;
	}
	if (buf[19] != '\n')
		ft_puterror();
	if (nb != 4)
		ft_puterror();
}

int				ft_startparsing(char *buf, int ltetri, t_env *env, t_elem *list)
{
	int		i;
	t_elem	*new;

	i = 0;
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->tetri = (char **)malloc(sizeof(char *) * 4)))
		ft_puterror();
	while (i < 4)
	{
		if (!(new->tetri[i++] = ft_strnew(4)))
			return (0);
	}
	new->letter = ltetri;
	new->next = 0;
	ft_do_list(buf, new, env, list);
	return (1);
}

int				ft_malloc_map(t_env *env)
{
	int y;
	int x;

	y = 0;
	if (!(env->map = (char **)malloc(sizeof(char *) * (env->len_map + 1))))
		return (0);
	env->map[(env->len_map)] = 0;
	while (y < env->len_map)
	{
		if (!(env->map[y] = ft_strnew(env->len_map + 1)))
			return (0);
		x = 0;
		while (x < env->len_map)
		{
			env->map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (1);
}

int				ft_start_map(int ltetri, t_env *env)
{
	int i;
	int len_min;

	if (ltetri > 26 || ltetri == 0)
		ft_puterror();
	len_min = ltetri * 4;
	i = 1;
	while ((i * i) < len_min)
		i++;
	env->len_map = i;
	if (!(ft_malloc_map(env)))
		return (0);
	return (1);
}

void			ft_free_map(t_env *env)
{
	int y;

	y = 0;
	while (env->map[y])
	{
		free(env->map[y]);
		y++;
	}
	free(env->map);
}
