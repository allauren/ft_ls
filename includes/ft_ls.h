/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:04:12 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 19:35:17 by allauren         ###   ########.fr       */
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
	char		*name;
	int			folder;
	char		*path;
	DIR			*dir;
	t_dirent	*odir;
	int			error;
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
char		*getfolder_open(char *str, t_data *data);
/*
 *** Display functions
 */
void		ft_print_folder(char *str, t_env *env);
t_list *newlstdata(t_data *data);
void	ft_wrong_folder(char *str);
void	ft_usage(char *str);
void		print_wfolder(t_list **lst);
void		print_ofolder(t_list **lst);
/*
 * * Del functions
 */
void		deldata(t_data *data);
t_list		*ft_deldate(t_list *prev, t_list *lst, t_list **start);
/*
 * * sort functions
 */

long int		ft_sortalpha(void *content1, void *content2);

#endif
