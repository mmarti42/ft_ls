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

static	int setFlags(char *av)
{
	while (*++av)
	{
		if (*av != 'a' && *av != 'l' && *av != 'R' && *av != 'r' && *av != 't')
			return (error(*av));
		if (*av == 'a')
			a = 1;
		else if (*av == 'l')
			l = 1;
		else if (*av == 'R')
			R = 1;
		else if (*av == 'r')
			r = 1;
		else if (*av == 't')
			t = 1;
	}
	return (0);
}

static	int	getFlags(char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (av[i][0] == '-')
		{
			if (setFlags(av[i]) < 0)
				return (-1);
		}
		else
			return (i);
	}
	return (0);
}

t_obj *rec(struct stat *stbuf, t_obj *files, char *av)
{
	t_obj *flist;

	flist = 0;
	if (!files)
	{
		files = new_obj(0, av, stbuf);
		flist = files;
	}
	else
	{
		if (t)
			by_time(flist, new_obj(0, av, stbuf));
		else
			by_name(files, new_obj(0, av, stbuf));
		return (files);
	}
	return (flist);
}

void getFiles(char **argv, int dirs)
{
	struct stat stbuf;
	t_obj *files;

	files = 0;
	if (dirs == 0)
		return ;
	while (argv[dirs])
	{
		if (lstat(argv[dirs], &stbuf) < 0)
			write(1, "No such file or directory\n", 26);
		else
		{
			if (S_ISREG(stbuf.st_mode) > 0)
				files = rec(&stbuf, files, argv[dirs]);
		}
		dirs++;
	}
	show_obj(files);
}

int			main(int argc, char **argv)
{
	int endfl;

	endfl = getFlags(argv);
	if (endfl < 0)
		return (-1);
	else
		getFiles(argv, endfl);
	return (0);
}