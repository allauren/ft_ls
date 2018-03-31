/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:01:42 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 19:17:43 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_wfolder(t_list **lst)
{
	t_data	*val;
	t_list	*t;
	t_list	*prev;

	t = *lst;
	prev = NULL;
	while (t)
	{
		val = (t_data *)t->content;
		if (!val->error)
		{
			ft_wrong_folder(val->name);
			t = ft_deldate(prev, t, lst);
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
}

void		print_ofolder(t_list **lst)
{
	t_data	*val;
	t_list	*t;
	t_list	*prev;

	t = *lst;
	prev = NULL;
	while (t)
	{
		val = (t_data *)t->content;
		if (val->folder)
		{
			ft_printf("%s\n",val->name);
			t = ft_deldate(prev, t, lst);
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
}
