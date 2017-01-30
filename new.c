/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:37:55 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/30 19:43:34 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_puterror(void)
{
	write(2, "error\n", ft_strlen("error\n"));
	exit (0);
}

int				ft_isvalid(char *buf)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (buf[i])
	{
		if (buf[i] != '#' || buf[i] != '.' || buf[i] != '\n')
			ft_puterror();
		if (buf[i] == '#')
			nb++;
		if (buf[i] == '\n' && (i != 4 || i != 9 || i != 14 || i != 19 || i != 20))
			ft_puterror();
		i++;
	}
	if (nb != 4)
		ft_puterror();
	return (1);
}

int				ft_addelem(t_env *env, t_elem *list, t_elem *new)
{
	t_elem *tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = list;
	if (env->first->tetri == NULL)
	{
		env->first->tetri = new->tetri;
		env->first->ltetri = new->ltetri;
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

int				ft_startparsing(char *buf, int ltetri, t_env *env, t_elem *list)
{
	char	**tetri;
	int 	i;
	int		j;
	int		k;
	t_elem	*new;

	i = 0;
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->tetri = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	new->tetri[4] = '\0';
	while (new->tetri[i])
	{
		if (!(new->tetri[i] = ft_strnew(5)))
			return (0);
		i++;
	}
	i = 0;
	k = 0;
	while (k < 4)
	{
		j = 0;
		while (buf[i] != \n)
		{
			new->tetri[k][j] = buf[i];
			i++;
			j++;
		}
		k++;
		i++;
	}
	new->letter = ltetri;
	ft_addelem(env, list, new);
	return (1);
}

int				ft_checkx(int x, int y, t_elem *tmp)
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
		if (tmp->tetri[y][x + 1] == '#')
			liaison++;
		if (tmp->tetri[y][x - 1] == '#')
			liaison++;
	}
	return (liaison);
}

int				ft_checky(int x, int y, t_elem *tmp)
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

void			ft_checktetri(t_env *env)
{
	int		x;
	int		y;
	t_elem	*tmp;
	int		liaison;

	tmp = env->first;
	while (tmp->next != NULL)
	{
		y = 0;
		liaison = 0;
		while (tmp->tetri[y])
		{
			x = 0;
			while (tmp->tetri[y][x])
			{
				if (tmp->tetri[y][x] == '#')
				{
					if ((ft_checkx(x, y, tmp) + ft_checky (x, y, tmp)) == 0)
						ft_puterror();
					liaison += (ft_checkx(x, y, tmp) + ft_checky(x, y, tmp));
				}
			}
		}
		(liaison < 6) ? (liaison = 0) : ft_puterror;
	}
}

int				ft_checkfile(char *av, t_env *env, t_elem *list)
{
	int			fd;
	char		*buf;
	int			ltetri;

	ltetri = 0;
	if (!(buf = ft_strnew(22)))
		return (0);
	if (!(fd = open(av, O_RDONLY)))
		ft_puterror();
	while (read(fd, buf, 21))
	{
		if (!(ft_isvalid(buf)))
			return (0);
		ft_startparsing(buf, ltetri, env, list);
		ltetri++;
	}
	env->len_map =  (4 * ltetri);
	
	if (!(ft_checktetri(env)))
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_env		*env;
	t_elem		*list;

	if (ac != 2)
		return (0);
	if(!(list = (t_elem*)malloc(sizeof(t_elem) * 26)))
		return (0);
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	list->next = NULL;
	env->first = list;
	ft_checkfile(av[1], env, list);
	ft_algo(list, env);
	return (0);
}
