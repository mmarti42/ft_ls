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

//void get_file_type(unsigned char type)
//{
//	if (type == DT_BLK)
//		printf("Block device");
//	else if (type == DT_DIR)
//		printf("Directory");
//	else if (type == DT_CHR)
//		printf("Character device");
//	else if (type == DT_FIFO)
//		printf("FIFO");
//	else if (type == DT_REG)
//		printf("File");
//	else if (type == DT_SOCK)
//		printf("local domain socket");
//	else if (type == DT_LNK)
//		printf("Symbolic link");
//	else if (type == DT_UNKNOWN)
//		printf("Unknown");
//}

static DIR				*ft_opendir(char *str)
{
	DIR		*dir;

	if (!(dir = opendir(str)))
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (0);
	}
	return (dir);
}

t_obj *recursive_search(DIR *dir, char *cur_dir, void(*sort)(t_obj*, t_obj*),
		void (*show)(t_obj*))
{
	struct dirent *dirent;
	t_obj *lst;
	t_obj *curr;
	struct stat *stbuf;

	stbuf = 0;
	lst = 0;
	curr = 0;
	while ((dirent = readdir(dir)))
	{
		if (!g_a && dirent->d_name[0] == '.')
			continue;
		if (g_l)
			lstat(dirent->d_name, stbuf);
		if (!lst)
			lst = new_obj(dirent, cur_dir, stbuf);
		else
		{
			curr = new_obj(dirent, cur_dir, stbuf);
			sort(lst, curr);
		}
		if (g_R && curr && curr->type == DT_DIR && ft_strcmp(curr->name, ".")
		&& ft_strcmp(curr->name, ".."))
			search(curr->path, sort, show);
	}
	closedir(dir);
	return (lst);
}

void search(char *dirname, void(sort(t_obj*, t_obj*)), void(show(t_obj*)))
{
	DIR		*dir;
	t_obj*	lst;

	if (!(dir = ft_opendir(dirname)))
		return ;
	lst = recursive_search(dir, dirname, sort, show);
	show(lst);
	write(1, "\n", 1);
}
