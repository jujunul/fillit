/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:41 by juthierr          #+#    #+#             */
/*   Updated: 2017/01/04 18:48:42 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void		ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

void		ft_checkfile(char *av)
{
	int fd;
	if(!(fd = open(av[1], O_RDONLY)))
	{
		ft_puterror("Fichier introuvable\n");
		return (0);
	}
}
int			main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!(ft_checkfile(av[1]))	
		return (0);
}
