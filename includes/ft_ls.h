/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:04:12 by allauren          #+#    #+#             */
/*   Updated: 2018/04/03 01:17:52 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "printf.h"
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>
# define OPT			env->o
# define NAME			data->path + data->name
# define IENV			env->current ? "." : av[env->i]

typedef struct dirent	t_dirent;
typedef int				t_bool;

typedef struct			s_options
{
	t_bool		l;
	t_bool		br;
	t_bool		a;
	t_bool		r;
	t_bool		t;
}						t_options;

typedef struct			s_env
{
	int			i;
	int			current;
	int			pass;
	char		*tmp;
	long int	(*fct)(void *, void *);
	t_options	o;
	t_list		*lst;
	t_list		*lst2;
	t_dirent	*odir;
	int			tot;
	DIR			*dir;
}						t_env;

typedef struct			s_data
{
	int			folder;
	char		*path;
	int			name;
	struct stat	buf;
	DIR			*dir;
	int			error;
}						t_data;

/*
** Parsing function
*/

void					ft_parse_args(int ac, char **av, t_env *env);
void					ft_usage(char *str);
void					ft_lst_merge_sort(t_list **list, long int
						(*f)(void *, void *));
void					get_all_folder(t_list **lst, t_env *env);
/*
** Dir functions
*/
void					concatpathd(t_data *data, char *str, char *name);
int						displaydir(char *str, t_env *env);
int						ft_is_current_folder(char *str, t_env *env);
char					*getfolder_open(char *str, t_data *data);
void					filldata(t_data **data, t_env *env, t_data *c);
/*
*** Display functions
*/
void					ft_print_folder(char *str, t_env *env);
t_list					*newlstdata(t_data *data);
void					ft_wrong_folder(char *str);
void					ft_usage(char *str);
void					print_wfolder(t_list **list, t_env *env);
void					print_ofolder(t_list **lst, t_env *env);
void					print_all(t_data *val, t_env *env);
void					print_dir(t_env *env, t_data *data, int i);
void					print_link(t_data *data);
void					print_size(t_data *data, char c);
void					print_right(t_data *val);
void					ft_set_values(char *ptr, int t);
void					select_type(mode_t mode, char *c);
void					print_mode(mode_t mode);
/*
** Del functions
*/
void					deldata(t_data *data);
t_list					*ft_deldate(t_list *prev, t_list *lst, t_list **start);
void					elemdel(t_list **lst);
char					*concatpath(char *str, char *name);
/*
** sort functions
*/
long int				ft_sortalpha(void *content1, void *content2);
long int				ft_sortralpha(void *content1, void *content2);
long int				ft_sorttime(void *cont1, void *cont2);
long int				ft_sortrtime(void *cont1, void *cont2);
/*
** l functions
*/
int						is_dir(char *str, struct stat *buf);
int						is_link(char *str, t_env *env);
char					*get_link(t_data **data, char *path, char *str);
void					print_lfolder(t_list **lst, t_env *env);

#endif
