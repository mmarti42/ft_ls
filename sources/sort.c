/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 06:11:32 by mmarti            #+#    #+#             */
/*   Updated: 2019/07/04 06:11:34 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

void	bubble_sort(t_obj *lst)
{
	int i;
	t_obj *tmp;

	i = -1;
	if (!lst)
		return ;
	while (++i < 5 && lst)
	{
		tmp = lst->next;
		if (ft_strcmp(lst->name, tmp->name) > 0)
		{
			lst->next = tmp;
			tmp->next = lst;
		}
		lst = lst->next;
	}
	bubble_sort(lst);
}

t_obj	*skip(t_obj *lst, int i)
{
	while (i--)
	{
		if (!lst)
			return (0);
		lst = lst->next;
	}
	return (lst);
}

t_obj *merge(t_obj *lst1, t_obj *lst2, int i)
{
	//todo
}

void	sort(t_obj *lst, int i)
{
	//todo
}


