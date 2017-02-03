/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:10:15 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/03 19:11:10 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_puterror(void)
{
	write(1, "error\n", ft_strlen("error\n"));
	exit (0);
}

void				ft_isvalid(char *buf)
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
		if (buf[i] == '\n' && (i != 4 && i != 9 && i != 14 && i != 19 && i != 20))
			ft_puterror();
		i++;
	}
	if (nb != 4)
		ft_puterror();
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
		env->first->letter = new->letter;
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

void			ft_do_list(char *buf, t_elem *new, t_env *env, t_elem *list)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (k < 4)
	{
		j = 0;
		printf("lalala\n");	
		while (j < 4 && buf[i])
		{
			new->tetri[k][j] = buf[i];
			printf("%c\n", buf[i]);	
			j++;
			i++;
		}
		i++;
		k++;
	}
	ft_addelem(env, list, new);
	
	printf("lololo\n");	
}

int				ft_startparsing(char *buf, int ltetri, t_env *env, t_elem *list)
{
	int 	i;
	t_elem	*new;

	i = 0;
		
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->tetri = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	while (i < 4)
		if (!(new->tetri[i++] = ft_strnew(5)))
			return (0);
	new->letter = ltetri;
	new->next = NULL;
	ft_do_list(buf, new, env, list);
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
		if (x < 3 && tmp->tetri[y][x + 1] == '#')
			liaison++;
		if (x > 0 && tmp->tetri[y][x - 1] == '#')
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

int				ft_malloc_map(t_env *env)
{
	int y;

	y = 0;
	if (!(env->map = (char **)malloc(sizeof(char*) * env->len_map + 1)))
		return (0);
	env->map[(env->len_map + 1)] = 0;
	while (env->map[y])
	{
		if (!(env->map[y] = ft_strnew(env->len_map + 1)))
			return (0);
		env->map[y][(env->len_map + 1)] = '\0';
		y++;
	}
	return (1);
}

void			ft_checktetri(t_env *env)
{
	int		x;
	int		y;
	t_elem	*tmp;
	int		liaison;
	int		i;

	i = 0;
	tmp = env->first;
	while (i < env->nbtetri)
	{
		y = 0;
		liaison = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (tmp->tetri[y][x] == '#')
				{
					if ((ft_checkx(x, y, tmp) + ft_checky (x, y, tmp)) == 0)
						ft_puterror();
					liaison += (ft_checkx(x, y, tmp) + ft_checky(x, y, tmp));
				}
				x++;
			}
			y++;
		}
		tmp = tmp->next;
		i++;
		(liaison >= 6) ? (liaison = 0) : ft_puterror();
	}
}

int				ft_start_map(int ltetri, t_env *env)
{
	int i;
	int len_min;

	env->nbtetri = ltetri;
	len_min = ltetri * 4;
	i = 1;
	while ((i * i) < len_min)
		i++;
	env->len_map = i;
	if(!(ft_malloc_map(env)))
		return (0);
	return (1);
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
		ft_isvalid(buf);
		ft_startparsing(buf, ltetri, env, list);
		ltetri++;
	}
	if (!(ft_start_map(ltetri, env)))
		return (0);
	ft_checktetri(env);
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
	if (!(ft_checkfile(av[1], env, list)))
		return (0);
	printf("inwgnipwgnpiwr\n");
	while (ft_algo(list, env))
	{
		printf("test\n");
		env->len_map++;
		ft_free_map(env);
		if(!(ft_malloc_map(env)))
			return (0);
	}
	ft_putabstr(env->map);
	return (0);
}