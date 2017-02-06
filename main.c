/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:10:15 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/06 04:11:39 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_addelem(t_env *env, t_elem *list, t_elem *new)
{
	t_elem	*tmp;
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
		while (buf[i] != '\n')
		{
			new->tetri[k][j] = buf[i];
			j++;
			i++;
		}
		i++;
		k++;
	}
	ft_addelem(env, list, new);
}

int				main(int ac, char **av)
{
	t_env		*env;
	t_elem		*list;

	if (ac != 2)
		ft_puterror();
	if (!(list = (t_elem*)malloc(sizeof(t_elem) * 26)))
		ft_puterror();
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_puterror();
	list->next = NULL;
	env->first = list;
	if (!(ft_checkfile(av[1], env, list)))
		return (0);
	while (ft_algo(list, env))
	{
		env->len_map++;
		ft_free_map(env);
		if (!(ft_malloc_map(env)))
			ft_puterror();
	}
	ft_putabstr(env->map);
	return (0);
}
