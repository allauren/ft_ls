/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:03:21 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 16:06:46 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_usage(char *str)
{
	ft_printf("ft_ls illegal option %s\n Usage ls[lRart]");
	exit(-1);
}

void	ft_wrong_folder(char *str)
{
	ft_printf("ls: %s: No such file or directory\n", str);
}

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

char		*getfolder_open(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_memalloc(ft_strlen(str))))
	if (ft_strchr(str, '/')) 
	{
		while (str[i])
		{
			while (str[i] && str[i++] != '/')
				continue;
			if (str[i] && !(ft_strchr(&str[i], '/') ? *((char*)(ft_strchr(&str[i], '/') + 1)) : 0))
				break;
		}
	}
	return (i ? 
	


}

int		isvalidfolder(char *str)
{
	DIR			*dir;
	t_dirent	odir;
	char		*tmp;
	if (!(dir = open_dir(str)))
	{
		if (ft_strchr(str, '/') && (dir = open_dir(getfolder_open(str))))
			L
		else
			wrongfolder(str);
	
	
	}
	closedir(dir);
	return(1);
}

t_list		*handlefirst(int ac, char **av, t_env *env)
{
	while (env->i < ac || env->current)
	{
		if (!(cnt = ft_memalloc(sizeof(t_data))))
			ft_alexis();

		cnt->str = ft_strdup(IENV);
		ft_lstadd(&(env->lst), newlstdata(cnt));
		env->current = 0;
		env->i++;
	



}

long int		ft_sortalpha(void *content1, void *content2)
{
	t_data *cnt1;
	t_data *cnt2;

	cnt1 = content1;
	cnt2 = content2;
	return(ft_strcmp((char*) cnt1->str, (char*)cnt2->str));
}

void	ft_parse_args(int ac, char **av, t_env *env)
{
	t_data	*cnt;

	while (++env->i < ac && av[env->i][0] == '-')
		if (!ft_set_arg(av[env->i], env))
			break;
		env->current = env->i == ac;
}
	ft_lst_merge_sort((&env->lst), &ft_sortalpha);
	ft_get_folders(ac, av, env);
}
