/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:31:58 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 19:39:09 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*concatpath(char *str, char *name)
{
	char		*ret;

	if (!(ret = ft_memalloc(ft_strlen(str) + ft_strlen(name) + 1)))
		ft_alexis();
	ft_strcat(ret, str);
	ft_strcat(ret, name);
	return (ret);
}

t_list		*get_all_folder(t_data *c, t_list **dirlst, t_env *env)
{

	while ((env->odir = readdir(c->dir)))
	{
		if (
	
	
	}



}
			while ((d->odir = readdir(d->dir)))
				if (ft_strequ(d->odir->d_name, d->str))
					d->error = 1;
