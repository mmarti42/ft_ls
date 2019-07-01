/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:10:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/11 11:10:11 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"
#include <sys/types.h>

void		init_flags(t_flags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->R = 0;
	flags->r = 0;
	flags->t = 0;
}

int get_dir(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '/')
			return (i);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int dir;
	t_flags	flags;

	init_flags(&flags);
	dir = get_dir(argv);
	if (set_options(argv, &flags) < 0)
		return (0);
	ft_ls_main(dir, argv, &flags);
	return (0);
}