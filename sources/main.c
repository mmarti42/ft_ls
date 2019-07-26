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

int			get_flags(char **av)
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

t_obj		*rec(t_obj *files, char *av)
{
	t_obj *flist;

	flist = 0;
	if (!files)
	{
		files = new_obj(0, av);
		flist = files;
	}
	else
	{
		if (g_t)
			by_time(flist, new_obj(0, av));
		else
			by_name(files, new_obj(0, av));
		return (files);
	}
	return (flist);
}

t_dirs		*recdirs(char *str, t_dirs *dirs)
{
	t_dirs *tmp;

	if (!(tmp = (t_dirs *)malloc(sizeof(t_dirs))))
		return (0);
	tmp->dir = strdup(str);
	if (!dirs)
		return (tmp);
	while (dirs->next)
		dirs = dirs->next;
	dirs->next = tmp;
	return (dirs);
}

t_dirs		*get_files(char **argv, int endfl, void(show(t_obj *)))
{
	struct stat	stbuf;
	t_obj		*files;
	t_dirs		*dirs;

	dirs = 0;
	files = 0;
	if (endfl == -1)
		return (0);
	while (argv[++endfl])
	{
		if (lstat(argv[endfl], &stbuf) < 0)
			write(1, "No such file or directory\n", 26);
		else
		{
			if (S_ISDIR(stbuf.st_mode) == 0)
				files = rec(files, argv[endfl]);
			else
				dirs = recdirs(argv[endfl], dirs);
		}
	}
	show(files);
	return (dirs);
}

int			main(int argc, char **argv)
{
	int		endfl;
	t_dirs	*dirs;
	void(*sort) (t_obj*, t_obj*);
	void(*show) (t_obj*);

	argc = 0;
	endfl = get_flags(argv);
	get_pointers(&sort, &show);
	if (endfl < 0)
		return (-1);
	dirs = get_files(argv, endfl - 1, show);
	if (!dirs)
		dirs = recdirs(".", dirs);
	while (dirs)
	{
		search(dirs->dir, sort, show);
		dirs = dirs->next;
	}
	return (0);
}
