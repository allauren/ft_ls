/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:50:47 by allauren          #+#    #+#             */
/*   Updated: 2018/04/02 13:21:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int		get_i(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_strchr(&str[i], '/'))
	{
		while (str[i] && str[i++] != '/')
			continue;
		if (str[i] && !(ft_strchr(&str[i], '/') ? *((char*)(ft_strchr(&str[i], '/') + 1)) : 0))
			break;
	}
	return(i);
}
void	ft_usage(char *str)
{
	ft_printf("ft_ls illegal option %s\n Usage ls[lRart]\n", str);
	exit(-1);
}

void	ft_wrong_folder(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(&str[get_i(str)], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}
