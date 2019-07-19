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

//static DIR				*ft_opendir(t_obj **lst, char *str)
//{
//	DIR		*dir;
//	t_obj	*cur;
//
//	if (!(dir = opendir(str)))
//	{
//		if (errno == ENOTDIR)
//		{
//			if (!*lst)
//				*lst = new_obj(0, str);
//			else
//			{
//				cur = get_last(*lst);
//				cur->next = new_obj(0, str);
//			}
//			return (0);
//		}
//		ft_putstr(strerror(errno));
//		ft_putchar('\n');
//		return (0);
//	}
//	return (dir);
//}

//static void	recursive_search(t_flags *flags, char *cur_dir)
//{
//	DIR *dir;
//	t_obj *lst;
//	struct dirent *dirent;
//	t_obj *tmp;
//
//	lst = 0;
//	tmp = 0;
//	if (!(dir = ft_opendir(&lst, cur_dir)))
//		return ;
//	while ((dirent = readdir(dir)))
//	{
//		if (!(flags->a) && dirent->d_name[0] == '.')
//			continue ;
//		if (!lst)
//		{
//			lst = new_obj(dirent, cur_dir);
//			tmp = lst;
//		}
//		else
//		{
//			lst->next = new_obj(dirent, cur_dir);
//			lst = lst->next;
//		}
//		if (flags->R && lst->type == DT_DIR && ft_strcmp(lst->name, ".") && ft_strcmp(lst->name, ".."))
//			recursive_search(flags, lst->path);
//	}
//	closedir(dir);
//	write(1, "\n", 1);
//	ft_putstr(cur_dir);
//	write(1, ":\n", 2);
//	show_obj(tmp, flags);
//}

//t_obj			*search(t_flags *flags)
//{
//	while (*(flags->dirs))
//	{
//		recursive_search(flags, *(flags->dirs));
//		flags->dirs++;
//	}
//	return 0;
//}
