/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:03:21 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 23:55:44 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_set_arg(char *str, t_env *env)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'l')
			OPT.l = 1;
		else if (str[i] == 'R')
			OPT.R = 1;
		else if (str[i] == 'a')
			OPT.a = 1;
		else if (str[i] == 'r')
			OPT.r = 1;
		else if (str[i] == 't')
			OPT.t = 1;
		else
			ft_usage(str);
	}
	return (i != 1);
}


char		*getfolder_open(char *str, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	data->path = ft_strdup(str);
	if (!(ret = ft_memalloc(ft_strlen(str) + 1)))
		ft_alexis();
	while (str[i] && ft_strchr(&str[i], '/'))
	{
		while (str[i] && str[i++] != '/')
			continue;
		if (str[i] && !(ft_strchr(&str[i], '/') ? *((char*)(ft_strchr(&str[i], '/') + 1)) : 0))
			break;
	}
	data->name = i;
	ret = !i ? ft_strcat(ret, ".") : ft_strncat(ret, str, i);
	return (ret);
}

void		isvalidfolder(char *str, t_env *env)
{
	t_data		*d;
	t_dirent	*odir;
	char		*path;

	path = NULL;
	if (!(d = ft_memalloc(sizeof(t_data))))
		ft_alexis();
	path = getfolder_open(str, d);
	if (!(d->dir = opendir(str)) 
			|| !(d->error = 1))
		if ((d->folder = 1)
				&& (d->dir = opendir((path = getfolder_open(str, d)))))
		{
			while ((odir = readdir(d->dir)))
				if (ft_strequ(odir->d_name, d->path + d->name))
				{
					d->error = 1;
					if(lstat(d->path, &d->buf) == -1  &&  d->error++)
						ft_wrong_folder(d->path + d->name);
				}
		}
	ft_strdel(&path);
	ft_lstadd(&env->lst, newlstdata(d));
}

void		handlefirst(int ac, char **av, t_env *env)
{
	while (env->i < ac || env->current)
	{
		isvalidfolder(IENV, env);
		env->current = 0;
		env->i++;
	}
	env->pass = env->pass > 1;
	ft_lst_merge_sort((&env->lst), env->fct);
	print_wfolder(&env->lst, env);
	print_ofolder(&env->lst, env);
}

void	ft_parse_args(int ac, char **av, t_env *env)
{
	static long int (*tab[4])(void *, void*) = {ft_sortalpha, ft_sortralpha,
						ft_sorttime, ft_sortrtime};

	while (++env->i < ac && av[env->i][0] == '-')
		if (!ft_set_arg(av[env->i], env))
			break;
	env->current = (env->i == ac);
	env->fct = tab[OPT.t ? 2 + OPT.r : OPT.r];
	handlefirst(ac, av, env);
	env->current = 0;
	get_all_folder(&env->lst, env);
}
