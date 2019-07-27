/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:37:40 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/25 14:37:41 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

char	*ft_namejoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (0);
	while (*s1)
		str[i++] = *s1++;
	if (*--s1 != '/')
	    str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	return (str);
}

void		get_stats(t_obj* new, t_column *col) ////!!!!!!!!!!!!
{
    struct stat stbuf;

    lstat(new->path, &stbuf);

    new->time = stbuf.st_mtimespec.tv_sec;
    if (!g_l)
		return ;
    new->blocks = stbuf.st_blocks;
	new->mod = convert_perm(stbuf.st_mode);
	new->links = convert_links(stbuf.st_nlink);
	new->master = convert_uid(stbuf.st_uid);
	new->group = convert_gid(stbuf.st_gid);
	if (new->mod[0] != 'c' && new->mod[0] != 'b')
		new->size = convert_size(stbuf.st_size);
	else
	{
		new->maj = convert_maj(stbuf.st_rdev);
		new->min = convert_min(stbuf.st_rdev);
	}
	new->time_year = convert_year(new->time);
	new->time_day = convert_day(new->time);
	new->time_month = convert_month(new->time);
	if (new->mod[0] == 'l')
		new->linked_file = convert_linked_file(new->path);
	if (col)
		set_columns(new, col);
}

t_obj		*new_obj(struct dirent *dirent, char *str, t_column *col) ////!!!!!!!!!!!!!
{
	t_obj		*new;

	if (!(new = (t_obj *)ft_memalloc(sizeof(t_obj))))
		return (0);
	if (dirent)
	{
		new->name = strdup(dirent->d_name);
		new->path = ft_namejoin(str, new->name);
		new->type = dirent->d_type;
	}
	else
	{
		new->name = ft_strdup(str);
		new->path = ft_strdup(str);
		new->type = -1;
	}
	new->left = 0;
	new->right = 0;
	if (g_l || g_t)
		get_stats(new, col);
	return (new);
}

void	write_long(t_obj *lst, t_column *col)
{
	if (col && col->group)
	{
		ft_printf("%s %*s", lst->mod, col->links, lst->links);
		ft_printf(" %-*s %-*s", col->master, lst->master, col->group, lst->group);
		if (!lst->size)
			ft_printf(" %*s, %*s", col->maj, lst->maj, col->min, lst->min);
		else
			ft_printf(" %*s", col->size, lst->size);
		ft_printf(" %s %*s %*s", lst->time_month, col->time_day, lst->time_day, col->time_year, lst->time_year);
		ft_printf(" %s", lst->name);
		if (lst->linked_file)
			ft_printf(" -> %s", lst->linked_file);
		ft_printf("\n");
	}
}

void	write_name(t_obj *lst, t_column *col)
{
	if (!lst)
		return ;
	if (g_l)
		write_long(lst, col);
	else
		ft_printf("%s\n", lst->name);
}

void		show_obj(t_obj *lst, t_column *col)
{
	if (!lst)
		return ;
	show_obj(lst->left, col);
	write_name(lst, col);
	show_obj(lst->right, col);
}

void		show_objrev(t_obj *lst, t_column *col)
{
	if (!lst)
		return ;
	show_objrev(lst->right, col);
	write_name(lst, col);
	show_objrev(lst->left, col);
}

void show_not_sorted(t_obj* lst, t_column *col)
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