/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:26:11 by abartole          #+#    #+#             */
/*   Updated: 2018/12/15 19:40:36 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pain(void *a, size_t b)
{
	b = 0;
	free(a);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	if (f && lst)
	{
		list = f(lst);
		new = list;
		while (lst->next)
		{
			lst = lst->next;
			if (!(list->next = f(lst)))
			{
				ft_lstdel(&new, &pain);
				return (NULL);
			}
			list = list->next;
		}
		return (new);
	}
	return (NULL);
}
