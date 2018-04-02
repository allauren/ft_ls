/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:52:31 by allauren          #+#    #+#             */
/*   Updated: 2018/04/02 14:34:06 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void		ft_set_values(char *ptr, int t)
{
	static char		buf[8192];
	static int		i = 0;
	int				z;

	if (!i)
		ft_bzero(buf, 8192);
	z = -1;
	if (t)
	{
		if (8192 - i > 255)
			while (ptr[++z])
				buf[i++] = ptr[z];
		else
		{
			write(1, buf, i);
			i = 0;
			ft_set_values(ptr, t);
		}
	}
	else if (i)
	{
		write(1, buf, i);
		i = 0;
	}
}
