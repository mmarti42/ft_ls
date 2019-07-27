/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:34:26 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 16:49:49 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*link;

	temp = *alst;
	if (del != NULL)
	{
		while (temp)
		{
			link = temp->next;
			del((temp->content), (temp->content_size));
			free(temp);
			temp = link;
		}
		*alst = NULL;
	}
}
