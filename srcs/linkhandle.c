/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 23:28:24 by allauren          #+#    #+#             */
/*   Updated: 2018/04/03 01:00:56 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_link(t_data **data, char *path, char *str)
{
	(*data)->folder = 1;
	(*data)->error = 1;
	if (lstat(str, &(*data)->buf) == -1)
		(*data)->error = 3;
	return (path);
}

void		print_lfolder(t_list **lst, t_env *env)
{
	t_data	*val;
	t_list	*t;
	t_list	*prev;

	t = *lst;
	prev = NULL;
	while (t)
	{
		val = (t_data *)t->content;
		if (val->error == -1)
		{
			print_all(val, env);
			t = ft_deldate(prev, t, lst);
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
}
