/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:12:19 by juthierr          #+#    #+#             */
/*   Updated: 2016/11/27 21:01:38 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_countstr(char const *s, char c)
{
	int i;
	int nbstr;
	int j;

	i = 0;
	j = 0;
	nbstr = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i++] != c)
		{
			if (j == 0)
			{
				j = 1;
				nbstr++;
			}
		}
		else
			j = 0;
	}
	return (nbstr);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	size_t		len;
	int			nbstr;

	i = 0;
	if (!s || !c)
		return (NULL);
	nbstr = ft_countstr(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * nbstr + 1)))
		return (NULL);
	while (i < nbstr)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		tab[i++] = ft_strsub((s - len), 0, len);
	}
	tab[i] = NULL;
	return (tab);
}
