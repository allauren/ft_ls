/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:04:12 by allauren          #+#    #+#             */
/*   Updated: 2018/03/28 15:20:16 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#include "printf.h"
#include <dirent.h>
#define  OPT env->o
#define	 IENV env->current ? "." : av[env->i]
typedef struct dirent t_dirent;
typedef	enum		s_bool
{
	FALSE = 0,
	TRUE = 1,
}				t_bool;
typedef struct		s_options
{
	t_bool		l;
	t_bool		R;
	t_bool		a;
	t_bool		r;
	t_bool		t;
}				t_options;

typedef struct	s_env
{
	int			i;
	int			current;
	int			pass;
	t_options	o;
	t_list		*lst;
	DIR			*dir;

}				t_env;

typedef struct	s_data
{
	char		*str;
	char		*path;
	DIR			*dir;
	t_dirent	odir;
}				t_data;

/*
 ** Parsing function
 **/

void	ft_parse_args(int ac, char **av, t_env *env);
void	ft_usage(char *str);
void	ft_lst_merge_sort(t_list **list, long int
			(*f)(void *,void *));
/*
 ** Dir functions
 */

int		displaydir(char *str, t_env *env);
int		ft_is_current_folder(char *str, t_env *env);
void		ft_deldate(t_list *lst);
/*
 *** Display functions
 */
void		ft_print_folder(char *str, t_env *env);
t_list *newlstdata(t_data *data);

#endif
