/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:50:47 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 17:01:21 by allauren         ###   ########.fr       */
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
