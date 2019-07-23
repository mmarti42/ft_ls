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

char	*ft_namejoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 2;
	if (!(str = (char *)ft_memalloc(sizeof(str) * len)))
		return (0);
	while (i < len1)
		str[i++] = *s1++;
	str[i++] = '/';
	while (i < len)
		str[i++] = *s2++;
	str[len] = 0;
	return (str);
}

void get_stats(t_obj* new, struct stat *stbuf)
{
	new->mod = stbuf->st_mode;
	new->links = stbuf->st_nlink;
	new->master = stbuf->st_uid;
	new->group = stbuf->st_gid;
	new->time = stbuf->st_mtimespec.tv_sec;
	new->blocks = stbuf->st_blocks;
	new->size = stbuf->st_size;
}

t_obj		*new_obj(struct dirent *dirent, char *str, struct stat *stbuf)
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
	if (stbuf)
		get_stats(new, stbuf);
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

//void		free_obj(t_obj *lst)
//{
//	t_obj	*cur;
//	t_obj	*tmp;
//	if (!lst)
//		return ;
//	cur = lst;
//	while (cur)
//	{
//		free(cur->name);
//		free(cur->path);
//		tmp = cur;
//		free(tmp);
//		cur = cur->next;
//	}
//}