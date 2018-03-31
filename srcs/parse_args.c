/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:03:21 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 17:15:49 by allauren         ###   ########.fr       */
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

	i = 0;
	if (!(data->path = ft_memalloc(ft_strlen(str))))
		ft_alexis();
	while (str[i])
	{
		while (str[i] && str[i++] != '/')
			continue;
		if (str[i] && !(ft_strchr(&str[i], '/') ? *((char*)(ft_strchr(&str[i], '/') + 1)) : 0))
			break;
	}
	data->path = ft_strncat(data->path, str, i);
	data->str = ft_strdup(&str[i]);
	return (data->path);
}

void		isvalidfolder(char *str, t_env *env, int t)
{
	t_data		*d;
	char		*tmp;

	if (!(d = ft_memalloc(sizeof(t_data))))
		ft_alexis();
		d->name = ft_strdup(str);
	if (!(d->dir = open_dir(str)) 
			|| !(d->error = 1))
	{
		d->folder = 1;
		if (ft_strchr(str, '/') && (d->dir = open_dir(getfolder_open(str, d))))
		{
			while ((d->odir = readdir(d->dir)))
				if (ft_strequ(d->odir->d_name, d->str))
					d->error = 1;
		}
	}
	if (t)
		ft_strdel(&str);
	ft_lstadd(&env->lst, newlstdata(d));
}

void		*handlefirst(int ac, char **av, t_env *env)
{
	while (env->i < ac || env->current)
	{
		ft_isvalidfolder(IENV, env, !!env->current);
		env->current = 0;
		env->i++;
	}
	ft_lst_merge_sort((&env->lst), &ft_sortalpha);
	
}

void	ft_parse_args(int ac, char **av, t_env *env)
{
	t_data	*cnt;

	while (++env->i < ac && av[env->i][0] == '-')
		if (!ft_set_arg(av[env->i], env))
			break;
	env->current = (env->i == ac);
	handlefirst(ac, av, env);
	ft_get_folders(ac, av, env);
}
