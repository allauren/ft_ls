/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:02:27 by allauren          #+#    #+#             */
/*   Updated: 2018/04/03 00:36:19 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	ft_parse_args(argc, argv, &env);
	ft_set_values(NULL, 0);
	return (0);
}
