/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:34:52 by allauren          #+#    #+#             */
/*   Updated: 2018/03/31 17:01:29 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		deldata(t_data *data)
{

	ft_strdel(&data->str);
	ft_strdel(&data->path);
	closedir(data->dir);
	ft_memdel((void**)&data);
}

void		ft_deldate(t_list *lst)
{
	t_data *del;

	del = lst->content;
	ft_strdel(&del->str);
	ft_strdel(&del->path);
	closedir(del->dir);
	ft_memdel((void**)&lst->content);
	ft_memdel((void**)&lst);
}

t_list *newlstdata(t_data *data)
{
	t_list *ret;

	if (!(ret = ft_memalloc(sizeof(t_list))))
		ft_alexis();
	ret->content = data;
	return(ret);
}
