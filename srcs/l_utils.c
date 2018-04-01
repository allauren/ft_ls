/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:17:03 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 13:11:14 by allauren         ###   ########.fr       */
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
