/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:41 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/11 18:40:12 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"

void		ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

int			ft_isvalid(char *buf)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (buf[i])
	{
		if (buf[i] != '#' || buf[i] != '.' || buf[i] != '\n')
		{
			ft_puterror("fichier non valide\n");
			return (0);
		}
		if (buf[i] == '#')
			nb++;
		if (buf[i] == '\n' && (i != 4 || i != 9 || i != 14 || i != 19 || i != 20))
		{
			ft_puterror("fichier non valide\n");
			return (0);
		}
		i++;
	}
	if (nb != 4)
	{
		ft_puterror("fichier non valide\n");
		return (0);
	}
}

int			ft_checkfile(char *av)
{
	int 	fd;
	char	*buf;
	int		i;

	i = 0;
	if (!(buf = ft_strnew(22)))
		return (0);
	if (!(fd = open(av[1], O_RDONLY)))
	{
		ft_puterror("Fichier introuvable\n");
		return (0);
	}
	while (read(fd, buf, 21))
	{
		if(!(ft_isvalid(buf)))
			return (0);
		ft_startparsing(buf, i);
		i++;
	}

}

int			ft_startparsing(char *buf, int i)
{
	char **tetri;
	
	if (!(tetri = (char **)malloc(sizeof(char*)) * 5))
	/* lire le fichier en boucle */
	add_elem(&list, tetri);
}

void		init_list(t_list *list)
{
	list->tetri = NULL;
	list->first = NULL;
}

int			add_elem(t_list *liste, char **tetri)
{
	t_elem	*elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (1);
	elem->tetri = tetri;
	elem->next = liste->first;
	/* **(list->tetri); ? */
	list->first = elem;
	return (0);
}

void		aff_list(llist *list)
{
	t_elem	*elem;

	elem = list->first;
	while (elem)
	{
		printf("%d\n", elem->tetri);
		elem = elem->next;
	}
}

void		free_list(t_list *list)
{
	t_elem	*elem;

	elem = list->first;
	while (elem)
	{
		free(elem);
		elem = elem->next;
	}
}

int			main(int ac, char **av)
{
	t_list	list;

	init_list(&list);
	add_elem(&list, tetri);
	aff_list(&list);
	free_list(&list);
	if (ac != 2)
		return (0);
	if (!(ft_checkfile(av[1])))	
		return (0);
}
