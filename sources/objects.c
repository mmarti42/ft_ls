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

void get_stats(t_obj* new)
{
    struct stat stbuf;
    lstat(new->path, &stbuf);

    new->time = stbuf.st_mtimespec.tv_sec;
    if (!g_l)
		return ;
	new->mod = stbuf.st_mode;
	new->links = stbuf.st_nlink;
	new->master = stbuf.st_uid;
	new->group = stbuf.st_gid;
	new->blocks = stbuf.st_blocks;
	new->size = stbuf.st_size;
}

t_obj		*new_obj(struct dirent *dirent, char *str)
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
		get_stats(new);
	return (new);
}

void	write_name(t_obj* lst)
{
	if (!lst)
		return ;
	write(1, lst->name, ft_strlen(lst->name));
	write(1, "\n", 1);
}

void		show_obj(t_obj *lst)
{
	if (!lst)
		return ;
	show_obj(lst->left);
	write_name(lst);
	show_obj(lst->right);
}

void		show_objrev(t_obj *lst)
{
	if (!lst)
		return ;
	show_objrev(lst->right);
	write_name(lst);
	show_objrev(lst->left);
}

void		free_obj(t_obj *lst)
{
	if (!lst)
		return ;
	free_obj(lst->left);
	free_obj(lst->right);
	free(lst->name);
	free(lst->path);
	free(lst);
}