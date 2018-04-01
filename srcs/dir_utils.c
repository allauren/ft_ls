/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:31:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 19:36:09 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*concatpathd(t_data *data, char *str, char *name)
{

	data->name = ft_strlen(str) + 1;
	if (!(data->path = ft_memalloc(data->name + ft_strlen(name) + 1)))
		ft_alexis();
	ft_strcat(data->path, str);
	ft_strcat(data->path, "/");
	ft_strcat(data->path, name);
}

void		initfolder(t_env *env, t_list **lst, char *tmp)
{
	t_data		*content;

	if (!(content = ft_memalloc(sizeof(t_data))))
		ft_alexis();
	content->dir = env->dir;
	ft_lstadd(lst, newlstdata(content));
}

void		recucall(t_list *lst, t_list **dirlst, t_env *env, t_data *c)
{
	t_data	*data;
	char	*tmp;

	if (lst)
	{
		data = (t_data*)lst->content;
		print_all(data, env);
		recucall(lst->next, dirlst, env, c);
		tmp = concatpath(c->name, data->name);
		if (!data->folder && OPT.R && (!OPT.a || (!ft_strequ(data->name, ".")
				&& !ft_strequ(data->name, ".."))) && is_dir(tmp, &data->buf))
		{
			env->dir = opendir(tmp);
			initfolder(env, dirlst, tmp);
		}
		ft_strdel(&tmp);
		elemdel(&lst);
	}
}

void		get_all_folder(t_list **lst, t_env *env)
{
	t_data	*data;
	t_data	*c;
	t_list	*tmp;
	t_list *print;

	tmp = NULL;
//	while (lst && *lst)
//	{
	if (lst && *lst)
	{
		print = NULL;
		c = (t_data*)(*lst)->content;
		if (c->dir)
		{
			while ((env->odir = readdir(c->dir)))
				if (env->odir->d_name[0] != '.' || OPT.a)
				{
					filldata(data, env, c);
					ft_lstadd(&print, newlstdata(data));
				}
			ft_lst_merge_sort(&print, &ft_sortalpha);
			print_dir(env, c, !!print);
			recucall(print, &tmp, env, c);
			get_all_folder(&tmp,env);
		}
		else
		{
			print_dir(env, c, !!print);
			ft_wrong_folder(c->name);
		}
		*lst = ft_deldate(NULL, *lst, NULL);
		get_all_folder(lst, env);
	}
	//	}
}
