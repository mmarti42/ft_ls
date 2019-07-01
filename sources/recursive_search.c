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

void get_file_type(unsigned char type)
{
	if (type == DT_BLK)
		printf("Block device");
	else if (type == DT_DIR)
		printf("Directory");
	else if (type == DT_CHR)
		printf("Character device");
	else if (type == DT_FIFO)
		printf("FIFO");
	else if (type == DT_REG)
		printf("File");
	else if (type == DT_SOCK)
		printf("local domain socket");
	else if (type == DT_LNK)
		printf("Symbolic link");
	else if (type == DT_UNKNOWN)
		printf("Unknown");
}

static DIR				*ft_opendir(t_obj **lst, const char *str)
{
	DIR		*dir;
	t_obj	*cur;

	if (!(dir = opendir(str)))
	{
		if (errno == ENOTDIR)
		{

			if (!*lst)
				*lst = new_obj(0, str);
			else
			{
				cur = get_last(*lst);
				cur->next = new_obj(0, str);
			}
			return (0);
		}
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return (0);
	}
	return (dir);
}

static t_obj			*recursive_search(t_obj **lst, char *str, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*dirent;
	t_obj			*cur;

	cur = 0;
	if (!(dir = ft_opendir(lst, str)))
		return (0);
	while ((dirent = readdir(dir)))
	{

		if (cur == 0 && !(!flags->a && dirent->d_name[0] == '.'))
		{
			*lst = new_obj(dirent, str);
			cur = *lst;
		}
		else if (cur && !(!flags->a && dirent->d_name[0] == '.'))
		{
			cur->next = new_obj(dirent, str);
			cur = cur->next;
		}
		if (cur && flags->R && cur->type == DT_DIR && ft_strcmp(cur->name, CUR_DIR) != 0 && ft_strcmp(cur->name, PREV_DIR) != 0)
			recursive_search(&cur->content, ft_namejoin(str, cur->name), flags);
	}
	closedir(dir);
	return (*lst);
}

t_obj			*search(int dir, char **argv, t_flags *flags)
{
	t_obj	*lst;
	int		i;

	lst = 0;
	i = 0;
	if (!dir)
		recursive_search(&lst, ".", flags);
	else
	{
		while (i < dir)
		{
			recursive_search(&lst, argv[i], flags);
			++i;
		}
	}
	return (lst);
}
