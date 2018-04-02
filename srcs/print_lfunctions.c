/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:09:18 by allauren          #+#    #+#             */
/*   Updated: 2018/04/02 15:02:02 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_data *data)
{
	char *lnk;

	if (!(lnk = ft_memalloc(data->buf.st_size + 16)))
		ft_alexis();
	if (readlink(data->path, lnk, data->buf.st_size + 8) == -1 )
	{
		ft_wrong_folder(data->path);
	}
	else
	{
		ft_printf("%s ", data->path + data->name);
		ft_printf(" -> %s\n", lnk);
	}
	ft_strdel(&lnk);
}

void		print_right(t_data *val)
{
		if(getpwuid(val->buf.st_uid))
			ft_printf("%12s ", getpwuid(val->buf.st_uid)->pw_name);
		else
			ft_printf("%12d ", val->buf.st_gid);
		if(getgrgid(val->buf.st_gid))
			ft_printf("%10s ",getgrgid(val->buf.st_gid)->gr_name);
		else
			ft_printf("%10d ", val->buf.st_gid);
}

void		print_size(t_data *data, char c)
{
	if (c == 'b' || c == 'c')
	{
		if (minor(data->buf.st_rdev) >= 256)
			ft_printf("%10d, %#010x ", major(data->buf.st_rdev), minor(data->buf.st_rdev));
		else
			ft_printf("%10d, %10d ", major(data->buf.st_rdev), minor(data->buf.st_rdev));
	}
	else
		ft_printf("%23lld ", data->buf.st_size);
}

void		select_type(mode_t mode, char *c)
{
	if ((mode & S_IFREG)== S_IFREG)
		*c = '-';
	if ((mode & S_IFDIR) == S_IFDIR)
		*c = 'd';
	if ((mode & S_IFCHR) == S_IFCHR)
		*c = 'c';
	if ((mode & S_IFBLK) == S_IFBLK)
		*c = 'b';
	if ((mode & S_IFLNK) == S_IFLNK)
		*c = 'l';
	if ((mode & S_IFSOCK) == S_IFSOCK)
		*c = 's';
	if ((mode & S_IFIFO) == S_IFIFO)
		*c = 'p';
}

void	print_mode(mode_t mode)
{
	const char	chars[] = "rwxrwxrwx";
	char		buf[10];
	size_t		i;

	i = 0;
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
		i++;
	}
	buf[9] = '\0';
	ft_printf("%s ", buf);
}
