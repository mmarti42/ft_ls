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

t_obj		*rec(t_obj *files, char *av)
{
	t_obj *flist;

	flist = 0;
	if (!files)
	{
		files = new_obj(0, av, 0);
		flist = files;
	}
	else
	{
		if (g_t)
			by_time(flist, new_obj(0, av, 0));
		else
			by_name(files, new_obj(0, av, 0));
		return (files);
	}
	return (flist);
}

t_dirs		*recdirs(char *str, t_dirs *dirs)
{
	t_dirs *tmp;

	if (!(tmp = (t_dirs *)ft_memalloc(sizeof(t_dirs))))
		return (0);
	tmp->dir = strdup(str);
	tmp->next = 0;
	if (!dirs)
		return (tmp);
	while (dirs->next)
		dirs = dirs->next;
	dirs->next = tmp;
	return (dirs);
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
		if (lstat(argv[endfl], &stbuf) < 0)
			ft_printf("%s%s%s\n", "ls: ",
					argv[endfl], ": No such file or directory");
		else
		{
			if (S_ISDIR(stbuf.st_mode) == 0)
				files = rec(files, argv[endfl]);
			else
				dirs = recdirs(argv[endfl], dirs);
		}
		endfl++;
	}
	show(files, col);
	return (dirs);
}

int			main(int argc, char **argv)
{
	int						endfl;
	t_dirs					*dirs;
	void					(*sort)(t_obj*, t_obj*);
	void					(*show)(t_obj*, t_column*);
	t_dirs					*tmp;

	endfl = get_flags(argv);
	get_pointers(&sort, &show);
	if (endfl < 0)
		return (-1);
	dirs = get_files(argv, endfl, show);
	if (!dirs && !argv[endfl])
		dirs = recdirs(".", dirs);
	else
		sort_dirs(dirs);
	tmp = dirs;
	while (dirs)
	{
		if (argc - endfl > 1)
			ft_printf("%s:\n", dirs->dir);
		search(dirs->dir, sort, show);
		dirs = dirs->next;
		if (dirs)
			write(1, "\n", 1);
	}
	free_lst(tmp);
	return (0);
}
