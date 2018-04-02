/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:01:42 by allauren          #+#    #+#             */
/*   Updated: 2018/04/02 23:42:56 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_all(t_data *val, t_env *env)
{
	char c;
	char *tmp;

	c = '-';
	if (!OPT.l)
	{
		ft_set_values(val->path + val->name, 1);
		ft_set_values("\n", 1);
	}
	else if (val->error != 3)
	{
		tmp = ctime(&val->buf.st_mtimespec.tv_sec);
		select_type(val->buf.st_mode, &c);
		ft_printf("%c", c);
		print_mode(val->buf.st_mode);
		ft_printf("%3d ", val->buf.st_nlink);
		print_right(val);
		print_size(val, c);
		tmp[ft_strlen(tmp) - 9] = '\0';
		if ((ft_printf("%10s ", &tmp[4]) && c == 'l') ||
				!ft_printf("%s\n", val->path + val->name))
			print_link(val);
	}
	else
		ft_wrong_folder(val->path + val->name);
}

void		print_dir(t_env *env, t_data *data, int i)
{
	if (env->pass)
	{
		if (OPT.l)
			ft_printf(env->pass == 1 ? "%s:\n" : "\n%s:\n", NAME);
		else
		{
			if (env->pass != 1)
				ft_set_values("\n", 1);
			ft_set_values(NAME, 1);
			ft_set_values(":\n", 1);
		}
	}
	else
		env->pass = 2;
	if (OPT.l && i)
	{
		ft_printf("total %d\n", env->tot);
		env->tot = 0;
		env->current = 0;
	}
	if (data->error == 4)
		ft_wrong_folder(NAME);
}

void		print_wfolder(t_list **lst, t_env *env)
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
			env->pass = 2;
			ft_wrong_folder(val->path + val->name);
			t = ft_deldate(prev, t, lst);
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
}

void		print_ofolder(t_list **lst, t_env *env)
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
