/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:23:40 by allauren          #+#    #+#             */
/*   Updated: 2018/04/03 01:06:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long int		ft_sortalpha(void *content1, void *content2)
{
	t_data *cnt1;
	t_data *cnt2;

	cnt1 = content1;
	cnt2 = content2;
	return (ft_strcmp((cnt1->path + cnt1->name), (cnt2->path + cnt2->name)));
}

long int		ft_sortralpha(void *content1, void *content2)
{
	t_data *cnt1;
	t_data *cnt2;

	cnt1 = content1;
	cnt2 = content2;
	return (-ft_strcmp((cnt1->path + cnt1->name), (cnt2->path + cnt2->name)));
}

long int		ft_sortrtime(void *cont1, void *cont2)
{
	t_data		*data1;
	t_data		*data2;

	data1 = (t_data*)cont1;
	data2 = (t_data*)cont2;
	if (!(lstat(data1->path, &(data1->buf)) == -1))
	{
		if (!(lstat(data2->path, &(data2->buf)) == -1))
		{
			if (data1->buf.st_mtimespec.tv_sec
					!= data2->buf.st_mtimespec.tv_sec)
				return (data1->buf.st_mtimespec.tv_sec
						- data2->buf.st_mtimespec.tv_sec);
			else if (data1->buf.st_mtimespec.tv_nsec
					!= data2->buf.st_mtimespec.tv_nsec)
				return (data1->buf.st_mtimespec.tv_nsec
						- data2->buf.st_mtimespec.tv_nsec);
			else
				return (-ft_strcmp(data1->path + data1->name,
							data2->path + data2->name));
		}
	}
	return (0);
}

long int		ft_sorttime(void *cont1, void *cont2)
{
	t_data		*data1;
	t_data		*data2;

	data1 = (t_data*)cont1;
	data2 = (t_data*)cont2;
	if (!(lstat(data1->path, &(data1->buf)) == -1))
	{
		if (!(lstat(data2->path, &(data2->buf)) == -1))
		{
			if (data1->buf.st_mtimespec.tv_sec
					!= data2->buf.st_mtimespec.tv_sec)
				return (data2->buf.st_mtimespec.tv_sec
						- data1->buf.st_mtimespec.tv_sec);
			else if (data1->buf.st_mtimespec.tv_nsec
					!= data2->buf.st_mtimespec.tv_nsec)
				return (data2->buf.st_mtimespec.tv_nsec
						- data1->buf.st_mtimespec.tv_nsec);
			else
				return (ft_strcmp(data1->path + data1->name,
							data2->path + data2->name));
		}
	}
	return (0);
}
