/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:17:03 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 19:32:48 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

int		is_dir(char *str, struct stat *buf)
{
	if (lstat(str, buf) == -1)
		return (0);
	if ((buf->st_mode & S_IFCHR) != S_IFCHR && (buf->st_mode & S_IFBLK)
			!= S_IFBLK && (buf->st_mode & S_IFDIR))
		return (1);
	return (0);
}

void	filldata(t_data *data, t_env *env, t_data *c)
{
	if(!(data = ft_memalloc(sizeof(t_data))))
		ft_alexis();
	data->folder = env->odir->d_type ? env->odir->d_type != DT_DIR : 0;
	concatpath(data, c->name, env->odir->dname);
	if (OPT.l)
	{
		if(lstat(data->path, &data->buf) == -1 && (data->error = 3))
			env->current = 1;
		else if ((!ft_strequ(env->odir->d_name,("."))
					&& !ft_strequ(env->odir->d_name, (".."))))
			env->tot += data->buf.st_blocks;
	}
}
