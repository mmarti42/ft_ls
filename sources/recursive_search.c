/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:08:59 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/24 18:09:00 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

static DIR	*ft_opendir(char *str)
{
	DIR		*dir;

	if (!(dir = opendir(str)))
	{
		if (errno == EACCES)
		{
			write(1, "ls: ", 4);
			ft_putstr(str);
			write(1, ": ", 2);
		}
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (0);
	}
	return (dir);
}

t_obj		*ft_readdir(DIR *dir, char *cur_dir,
		void (*sort)(t_obj*, t_obj*), t_column *col)
{
	struct dirent	*dirent;
	t_obj			*lst;
	t_obj			*curr;

	lst = 0;
	while ((dirent = readdir(dir)))
	{
		if (!g_a && dirent->d_name[0] == '.')
			continue;
		if (!lst)
			lst = new_obj(dirent, cur_dir, col);
		else
		{
			curr = new_obj(dirent, cur_dir, col);
			sort(lst, curr);
		}
	}
	closedir(dir);
	return (lst);
}

void		get_dir(t_obj *lst, void (*sort)(t_obj*, t_obj*),
		void (*show)(t_obj*, t_column*))
{
	if (!lst)
		return ;
	get_dir(lst->left, sort, show);
	if (lst->type == DT_DIR && ft_strcmp(lst->name, ".")
		&& ft_strcmp(lst->name, ".."))
	{
		ft_printf("\n%s:\n", lst->path);
		search(lst->path, sort, show);
	}
	get_dir(lst->right, sort, show);
}

void		search(char *dirname, void (*sort)(t_obj*, t_obj*),
		void (*show)(t_obj*, t_column*))
{
	DIR			*dir;
	t_obj		*lst;
	t_column	*col;

	lst = 0;
	if (!(dir = ft_opendir(dirname)))
		return ;
	col = new_column();
	lst = ft_readdir(dir, dirname, sort, col);
	if (g_l && lst)
		ft_printf("total %d\n", col->total);
	show(lst, col);
	if (g_rr)
		get_dir(lst, sort, show);
	free_obj(lst);
}
