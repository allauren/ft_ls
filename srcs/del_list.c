/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:34:52 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 19:17:49 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		deldata(t_data *data)
{

	ft_strdel(&data->str);
	ft_strdel(&data->name);
	ft_strdel(&data->path);
	if (data->dir)
	closedir(data->dir);
}

t_list		*ft_deldate(t_list *prev, t_list *lst, t_list **start)
{
	t_data	*del;
	t_list	*ret;

	if (*start == lst)
		*start = (*(start))->next;
	if (prev)
		prev->next = lst->next;
	ret = lst->next;
	del = lst->content;
	deldata(del);
	ft_memdel((void**)&lst->content);
	ft_memdel((void**)&lst);
	return(ret);
}

t_list *newlstdata(t_data *data)
{
	t_list *ret;

	if (!(ret = ft_memalloc(sizeof(t_list))))
		ft_alexis();
	ret->content = data;
	return(ret);
}
