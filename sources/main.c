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

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (setflags(av[i]) < 0)
			return (-1);
		i++;
	}
	return (i);
}

t_obj		*rec(t_obj *files, char *av, t_column *col)
{
	t_obj *flist;

	flist = 0;
	if (!files)
	{
		files = new_obj(0, av, col);
		flist = files;
	}
	else
	{
		if (g_t)
			by_time(flist, new_obj(0, av, col));
		else
			by_name(files, new_obj(0, av, col));
		return (files);
	}
	return (flist);
}

t_dirs		*recdirs(char *str, t_dirs *dirs)
{
	t_dirs *tmp;
	t_dirs *first;

	first = dirs;
	if (!(tmp = (t_dirs *)ft_memalloc(sizeof(t_dirs))))
		return (0);
	tmp->dir = strdup(str);
	tmp->next = 0;
	if (!dirs)
		return (tmp);
	while (dirs->next)
		dirs = dirs->next;
	dirs->next = tmp;
	return (first);
}

t_dirs		*get_files(char **argv,
		int endfl, void (show(t_obj *, t_column*)))
{
	struct stat	stbuf;
	t_obj		*files;
	t_dirs		*dirs;
	t_column	*col;

	col = new_column();
	dirs = 0;
	files = 0;
	while (argv[endfl])
	{
		if (lstat(argv[endfl], &stbuf) == 0)
		{
			if (S_ISDIR(stbuf.st_mode) == 0)
				files = rec(files, argv[endfl], col);
			else
				dirs = recdirs(argv[endfl], dirs);
		}
		else
			ft_printf("%s%s%s\n", "ls: ",
					argv[endfl], ": No such file or directory");
		endfl++;
	}
	show(files, col);
	free(col);
	return (dirs);
}

int			main(int argc, char **argv)
{
	t_vars		a;

	a.endfl = get_flags(argv);
	get_pointers(&a.sort, &a.show);
	if (a.endfl < 0)
		return (-1);
	a.dirs = get_files(argv, a.endfl, a.show);
	if (!a.dirs && !argv[a.endfl])
		a.dirs = recdirs(".", a.dirs);
	else
		sort_dirs(a.dirs);
	a.tmp = a.dirs;
	while (a.dirs)
	{
		if (argc - a.endfl > 1)
			ft_printf("%s:\n", a.dirs->dir);
		search(a.dirs->dir, a.sort, a.show);
		a.dirs = a.dirs->next;
		if (a.dirs)
			write(1, "\n", 1);
	}
	free_lst(a.tmp);
	return (0);
}
