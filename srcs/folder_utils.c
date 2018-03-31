/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folder_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:42:32 by allauren          #+#    #+#             */
/*   Updated: 2018/03/28 14:58:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*cleanfold(char *str)
{
	char	*tmp;
	int		i;

	i = 0;

	if(!(tmp = ft_strdup(str)))
		ft_alexis();
	while(1)
	{
		while (tmp[i] && tmp[i] != '/')
			i++;
		if (!ft_strchr(&tmp[i + 1], '/'))
		{
			tmp[i] = '\0';
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int		ft_is_current_folder(char *str, t_env *env)
{
	char	*tmp;
	int		i;
	t_dirent	*odir;

	i = 0;
	tmp = ft_strchr(str, '/') ? cleanfold(str) : ft_strdup(".");
	while (!ft_strequ(tmp, ".") && tmp[i])
		i++;
	if(!(env->dir = opendir(tmp)))
		return (0);
	else
	{
		while((odir = readdir(env->dir)))
		{
			//ft_printf("%d %s %s\n ",ft_strequ(odir->d_name, i ? &tmp[i + 1] : tmp) , tmp, odir->d_name);
			if (ft_strequ(odir->d_name, i ? &tmp[i + 1] : str))
			{
				closedir(env->dir);
				ft_strdel(&tmp);
			//	ft_printf("%s\n", str);
				return (1);
			}
		}
	}
//	ft_printf("je suis content");
	closedir(env->dir);
	return (0);
}
