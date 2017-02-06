/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <juthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/02/03 17:35:02 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <libft.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_elem
{
	char			**tetri;
	int				letter;
	struct s_elem	*next;
}					t_elem;

typedef	struct		s_env
{
	struct s_elem	*first;
	char			**map;
	int				len_map;
	int				y_first;
	int				x_first;
	int				t_y;
	int				t_x;
}					t_env;

/*
** main
*/
int					ft_addelem(t_env *env, t_elem *list, t_elem *new);
void				ft_do_list(char *buf, t_elem *new,
					t_env *env, t_elem *list);
int					main(int ac, char **av);

/*
** algo.c
*/
int					do_tetri_fit(t_elem *elem, t_env *env, int y, int x);
void				put_in_map(t_elem *elem, t_env *env, int y, int x);
int					ft_algo(t_elem *elem, t_env *env);

/*
** ft_check
*/
void				ft_checktetri(t_env *env);
int					ft_checkfile(char *av, t_env *env, t_elem *list);
int					ft_x(int x, int y, t_elem *tmp);
int					ft_y(int x, int y, t_elem *tmp);

/*
** ft_error
*/
void				ft_puterror(void);

/*
** ft_parsing
*/
void				ft_isvalid(char *buf);
int					ft_startparsing(char *buf, int ltetri,
					t_env *env, t_elem *list);
int					ft_malloc_map(t_env *env);
int					ft_start_map(int ltetri, t_env *env);
void				ft_free_map(t_env *env);

/*
** tetri_in_map
*/
void				take_out_of_map(t_elem *elem, t_env *env);
void				save_prev(t_env *env, int t_y, int t_x);
int					tetri_is_not_in_condition(t_env *env, int y, int x);

#endif
