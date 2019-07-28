/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:17:24 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/27 21:19:21 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

void		show_objrev(t_obj *lst, t_column *col)
{
	if (!lst)
		return ;
	show_objrev(lst->right, col);
	write_name(lst, col);
	show_objrev(lst->left, col);
}

void		show_not_sorted(t_obj *lst, t_column *col)
{
	while (lst)
	{
		write_name(lst, col);
		lst = lst->right;
	}
}

void		free_obj(t_obj *lst)
{
	if (!lst)
		return ;
	free_obj(lst->left);
	free_obj(lst->right);
	free(lst->name);
	free(lst->path);
	free(lst->linked_file);
	free(lst->mod);
	free(lst->time_year);
	free(lst->time_month);
	free(lst->time_day);
	free(lst->size);
	free(lst->min);
	free(lst->maj);
	free(lst->master);
	free(lst->group);
	free(lst->links);
	free(lst);
}

void		sort_dirs(t_dirs *dirs)
{
	char		*tmp;
	t_dirs		*first;

	if (!dirs)
		return ;
	first = dirs;
	while (dirs->next)
	{
		if (ft_strcmp(dirs->dir, dirs->next->dir) > 0)
		{
			tmp = dirs->dir;
			dirs->dir = dirs->next->dir;
			dirs->next->dir = tmp;
			dirs = first;
		}
		else
			dirs = dirs->next;
	}
}

void		free_lst(t_dirs *lst)
{
	t_dirs		*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->dir);
		free(lst);
		lst = tmp;
	}
}
