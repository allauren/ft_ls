/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:02:27 by allauren          #+#    #+#             */
/*   Updated: 2018/03/28 16:45:04 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_concat_repo(char *str1, char *str2)
{
	char	*ret;

	if (!str1)
		return (str2);
	if(!(ret = ft_memalloc(ft_strlen(str1) + ft_strlen(str2) + 3)))
		ft_alexis();
	ft_strcat(ret, str1);
	ft_strcat(ret, "/");
	ft_strcat(ret, str2);
	return (ret);
}

void	dir_handle(t_env *env, t_list **lst)
{
	t_dirent	*odir;
	DIR			*tmp;
	t_list		*lst2 = NULL;
	t_list		*prev = NULL;
	t_data		*val;
	t_data		*val2;
	char		*lol = NULL;

	while ((*lst))
	{
		val2 = (*lst)->content;
		//	ft_printf("%s\n",val2->path);
		env->pass = env->pass ? ft_printf("\n%s:\n", val2->path) : 1;
		if (!(val2->dir = opendir(val2->str)))
			return;
		while((odir = readdir(val2->dir)))
		{
			if (odir->d_name[0] != '.' || OPT.a)
			{
				ft_printf("%s#\n", odir->d_name);
				if (OPT.R && !ft_strequ(odir->d_name, ".") 
						&& !ft_strequ(odir->d_name, "..")
						&& (tmp = opendir((lol = ft_concat_repo(val2->path, odir->d_name)))))
				{
					ft_printf("\n ici");
					if (!(val = ft_memalloc(sizeof(t_data))))
						ft_alexis();
					val->str = ft_concat_repo(val2->path, odir->d_name);
					val->path = ft_strdup(val->str);
					ft_lstadd(&lst2, ft_lstnew(val, sizeof(t_data)));
					ft_lstadd(&lst2, newlstdata(val));
					closedir(tmp);
				}
				ft_strdel(&lol);
			}
		}
		dir_handle(env, &lst2);
		prev = *lst;
		(*lst) = (*lst)->next;
		ft_deldate(prev);
	}
}

int		main(int argc, char *argv[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	ft_parse_args(argc, argv, &env);
	dir_handle(&env, &env.lst);


	return 0;
}
