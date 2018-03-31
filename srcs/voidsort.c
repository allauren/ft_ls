/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:23:40 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 18:28:33 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

long int		ft_sortalpha(void *content1, void *content2)
{
	t_data *cnt1;
	t_data *cnt2;

	cnt1 = content1;
	cnt2 = content2;
	return(ft_strcmp((char*) cnt1->name, (char*)cnt2->name));
}


