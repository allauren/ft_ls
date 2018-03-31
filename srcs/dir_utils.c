/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:31:58 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 22:44:35 by allauren         ###   ########.fr       */
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

void		initfolder(t_env *env, t_list **lst)
{
	t_data *content;

	if (!(content = ft_memalloc(sizeof(t_data))))
		ft_alexis();
	content->dir = env->dir;
	content->name = env->tmp;
	ft_lstadd(lst, newlstdata(content));
}

void		recucall(t_list **lst, t_list **dirlst, t_env *env, t_data *c)
{
	t_data	*data;

	if (lst && *lst)
	{
			data = (t_data*)(*lst)->content;
			env->pass = ft_printf("%s\n", data->name);
			if ((*lst)->next)
				recucall(&(*lst)->next, dirlst, env, c);
			if (OPT.R && !ft_strequ(data->name, ".") 
						&& !ft_strequ(data->name, "..")
						&& (env->dir = opendir((env->tmp = concatpath(c->name, data->name)))))
					initfolder(env, dirlst);
			else if (env->tmp)
				ft_strdel(&env->tmp);
			elemdel(lst);
//			ft_printf(" dir %s\n", (env->tmp = concatpath(c->name, data->name)));
	}

}

void		get_all_folder(t_list **lst, t_list *dirlst, t_env *env)
{
	t_data	*data;
	t_data	*c;
	t_list	*tmp;
	t_list *print;

	print = NULL;
	while (lst && *lst)
	{
		c = (t_data*)(*lst)->content;
		env->pass = env->pass ? ft_printf(env->pass == 1 ? "%s:\n" : "\n%s:\n",c->name) : 1;
		while ((env->odir = readdir(c->dir)))
		{
			if (env->odir->d_name[0] != '.' || OPT.a)
			{
				if(!(data = ft_memalloc(sizeof(t_data))))
					ft_alexis();
				data->name = ft_strdup(env->odir->d_name);
				ft_lstadd(&print, newlstdata(data));
			}
		}
		ft_lst_merge_sort(&print, &ft_sortalpha);
		recucall(&print, &dirlst, env, c);
		get_all_folder(&dirlst, NULL, env);
		*lst = ft_deldate(NULL, *lst, NULL);
	}
}
