/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:31:58 by allauren          #+#    #+#             */
/*   Updated: 2018/03/27 16:23:10 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_sorted(t_env *env)
{
	t_dirent	*odir;

	while((odir = readdir(env->dir)))
	{
		if (odir->d_name[0] != '.' || OPT.a)
			ft_printf("%s\n", odir->d_name);
	}
}

void	print_rsorted(t_env *env)
{
		t_dirent *odir;

		if((odir = readdir(env->dir)))
		{
			print_rsorted(env);
		}
		else
			return;
		if (odir->d_name[0] != '.' || OPT.a)
			ft_printf("%s\n", odir->d_name);
}


int		displaydir(char *str, t_env *env)
{

	if (!(env->dir = opendir(str)))
		return (0);
	if (OPT.r)
		print_rsorted(env);
	else
		print_sorted(env);
	closedir(env->dir);
	return (1);
}
