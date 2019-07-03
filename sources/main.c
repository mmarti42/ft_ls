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

static	t_flags		*init_flags(t_flags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->R = 0;
	flags->r = 0;
	flags->t = 0;
	flags->dirs = 0;
	return (flags);
}

static	int setFlags(t_flags *flags, char *av)
{
	while (*++av)
	{
		if (*av != 'a' && *av != 'l' && *av != 'R' && *av != 'r' && *av != 't')
			return (error(*av));
		if (*av == 'a')
			flags->a = 1;
		else if (*av == 'l')
			flags->l = 1;
		else if (*av == 'R')
			flags->R = 1;
		else if (*av == 'r')
			flags->r = 1;
		else if (*av == 't')
			flags->t = 1;
	}
	return (0);
}

static	int	getFlags(t_flags *flags, char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (av[i][0] == '-')
		{
			if (setFlags(flags, av[i]) < 0)
				return (-1);
		}
		else
			return (i);
	}
	return (0);
}

static	void	getDirs(t_flags *flags, char **argv, int argc, int start)
{
	int i;

	i = 0;
	if (start == 0)
	{
		flags->dirs = (char **)malloc(sizeof(char *) * 2);
		(flags->dirs)[i++] = ".";
	}
	else
	{
		flags->dirs = (char **)ft_memalloc(sizeof(char *) * argc - start + 1);
		while (argv[start])
			(flags->dirs)[i++] = argv[start++];
	}
	(flags->dirs)[i] = 0;
}

int			main(int argc, char **argv)
{
	int dirs;
	t_flags	flags;
	t_obj	*result;

	dirs = getFlags(init_flags(&flags), argv);
	if (dirs < 0)
		return (-1);
	else
		getDirs(&flags, argv, argc, dirs);
	result = search(&flags);
	//show_obj(result);
	return (0);
}