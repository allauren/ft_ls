/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:01:42 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 17:50:01 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_ofolder(t_list *lst)
{
	t_data	*val;
	t_list	*t;
	t_list	*prev;
	t = lst;

	prev = NULL;
	while (t)
	{
		val = (t_data *)t->content;
		if (val->error)
		{
			ft_printf("%s\n", val->name);
			
		}
		prev = t;
		t = t->next;
	}
	t = lst;
	while (t)
	{
		val = (t_data *)t->content;
		if (val->error)
			ft_printf("%s\n", val->name);
		t = t->next;
	}



}
