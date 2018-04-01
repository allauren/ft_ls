/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:31:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 11:45:09 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*concatpath(char *str, char *name)
{
	char		*ret;

	if (!(ret = ft_memalloc(ft_strlen(str) + ft_strlen(name) + 2)))
		ft_alexis();
	ft_strcat(ret, str);
	ft_strcat(ret, "/");
	ft_strcat(ret, name);
	return (ret);
}

void		initfolder(t_env *env, t_list **lst, char *tmp, int err)
{
	t_data		*content;

	if (!(content = ft_memalloc(sizeof(t_data))))
		ft_alexis();
	content->dir = env->dir;
	content->error = err;
	content->name = ft_strdup(tmp);
	ft_lstadd(lst, newlstdata(content));
}

void		recucall(t_list **lst, t_list **dirlst, t_env *env, t_data *c)
{
	t_data	*data;
	char	*tmp;
	int		err;

	if (lst && *lst)
	{
		err = 0;
		data = (t_data*)(*lst)->content;
		print_all(data, env);
		if ((*lst)->next)
			recucall(&(*lst)->next, dirlst, env, c);
		tmp = concatpath(c->name, data->name);
		if (!data->folder && OPT.R && !ft_strequ(data->name, ".")
				&& !ft_strequ(data->name, "..") && is_dir(tmp, &data->buf))
		{
			env->dir = opendir(tmp);
			initfolder(env, dirlst, tmp, err);
		}
		ft_strdel(&tmp);
		elemdel(lst);
	}
}

void		get_all_folder(t_list **lst, t_env *env)
{
	t_data	*data;
	t_data	*c;
	t_list	*tmp;
	t_list *print;

	tmp = NULL;
	while (lst && *lst)
	{
		print = NULL;
		c = (t_data*)(*lst)->content;
			if (c->dir)
			{
			while ((env->odir = readdir(c->dir)))
			{
				if (env->odir->d_name[0] != '.' || OPT.a)
				{
					if(!(data = ft_memalloc(sizeof(t_data))))
						ft_alexis();
					data->folder = env->odir->d_type ?env->odir->d_type != DT_DIR : 0;
					data->name = ft_strdup(env->odir->d_name);
					data->path = concatpath(c->name, data->name);
					if(lstat(data->path, &data->buf) == -1 && (data->error = 3))
						env->current = 1;
					else if ((!ft_strequ(env->odir->d_name,("."))
							&& !ft_strequ(env->odir->d_name, (".."))))
						env->tot += data->buf.st_blocks;
					ft_lstadd(&print, newlstdata(data));
				}
			}
		ft_lst_merge_sort(&print, &ft_sortalpha);
		print_dir(env, c, !!print);
		recucall(&print, &tmp, env, c);
		get_all_folder(&tmp,env);
			}
		else
		{
			print_dir(env, c, !!print);
			ft_wrong_folder(c->name);
		}
		*lst = ft_deldate(NULL, *lst, NULL);
	}
}
